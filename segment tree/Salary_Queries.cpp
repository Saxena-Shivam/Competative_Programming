#include <bits/stdc++.h>
using namespace std;
#define ll long long

class SegmentTree
{
    int n;
    vector<ll> tree;

public:
    SegmentTree() {}
    SegmentTree(int _n)
    {
        n = _n;
        tree.resize(4 * n);
    }
    void build(int v, int tl, int tr)
    {
        if (tl == tr)
        {
            tree[v] = 0;
            return;
        }
        int tm = (tl + tr) / 2;
        build(2 * v, tl, tm);
        build(2 * v + 1, tm + 1, tr);
        tree[v] = tree[2 * v] + tree[2 * v + 1];
    }
    ll query(int v, int tl, int tr, int l, int r)
    {
        if (tl > r || tr < l)
            return 0;
        if (tl >= l && tr <= r)
            return tree[v];
        int tm = (tl + tr) / 2;
        return query(2 * v, tl, tm, l, r) + query(2 * v + 1, tm + 1, tr, l, r);
    }
    void update(int v, int tl, int tr, int id, ll val)
    {
        if (tl == tr)
        {
            tree[v] += val;
            return;
        }
        int tm = (tl + tr) / 2;
        if (id <= tm)
            update(2 * v, tl, tm, id, val);
        else
            update(2 * v + 1, tm + 1, tr, id, val);
        tree[v] = tree[2 * v] + tree[2 * v + 1];
    }
    void build()
    {
        build(1, 0, n - 1);
    }
    ll query(int l, int r)
    {
        return query(1, 0, n - 1, l, r);
    }
    void update(int id, ll val)
    {
        update(1, 0, n - 1, id, val);
    }
};

int main()
{
    ll n, q;
    cin >> n >> q;
    vector<ll> a(n), all;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        all.push_back(a[i]);
    }
    vector<tuple<char, ll, ll>> queries;
    for (int i = 0; i < q; i++)
    {
        char c;
        cin >> c;
        if (c == '!')
        {
            ll pos, val;
            cin >> pos >> val;
            queries.push_back({c, pos, val});
            all.push_back(val);
        }
        else
        {
            ll l, r;
            cin >> l >> r;
            queries.push_back({c, l, r});
            all.push_back(l);
            all.push_back(r);
        }
    }
    sort(all.begin(), all.end());
    all.erase(unique(all.begin(), all.end()), all.end());
    auto getId = [&](ll x)
    {
        return lower_bound(all.begin(), all.end(), x) - all.begin();
    };
    int N = all.size();
    SegmentTree st(N);
    st.build();
    for (int i = 0; i < n; i++)
    {
        st.update(getId(a[i]), 1);
    }
    for (auto &qq : queries)
    {
        char c;
        ll x, y;
        tie(c, x, y) = qq;
        if (c == '!')
        {
            int pos = x - 1;
            st.update(getId(a[pos]), -1);
            a[pos] = y;
            st.update(getId(y), 1);
        }
        else
        {
            int L = lower_bound(all.begin(), all.end(), x) - all.begin();
            int R = upper_bound(all.begin(), all.end(), y) - all.begin() - 1;
            if (L > R)
                cout << 0;
            else
                cout << st.query(L, R);
            cout << "\n";
        }
    }
}