#include <bits/stdc++.h>
using namespace std;
#define ll long long
class SegmentTree
{
private:
    vector<ll> tree;
    int n;
    void build(vector<ll> &a, int v, int tl, int tr)
    {
        if (tl == tr)
        {
            tree[v] = a[tl];
            return;
        }
        int tm = (tl + tr) / 2;
        build(a, 2 * v, tl, tm);
        build(a, 2 * v + 1, tm + 1, tr);
        tree[v] = tree[2 * v] & tree[2 * v + 1];
    }

    void update(int v, int tl, int tr, int pos, int val)
    {
        if (tl == tr)
        {
            tree[v] = val;
            return;
        }
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(2 * v, tl, tm, pos, val);
        else
            update(2 * v + 1, tm + 1, tr, pos, val);

        tree[v] = (tree[2 * v] & tree[2 * v + 1]);
    }

    ll query(int v, int tl, int tr, int l, int r)
    {
        if (tl > r || tr < l)
        {
            return (1LL << 32) - 1;
        }
        if (tl >= l && tr <= r)
            return tree[v];
        int tm = (tl + tr) / 2;
        ll left = query(2 * v, tl, tm, l, r);
        ll right = query(2 * v + 1, tm + 1, tr, l, r);
        return (left & right);
    }

public:
    SegmentTree(int _n)
    {
        n = _n;
        tree.resize(4 * n);
    }

    void build(vector<ll> &a)
    {
        build(a, 1, 0, n - 1);
    }

    void update(int pos, char c)
    {
        update(1, 0, n - 1, pos, c);
    }

    ll query(int l, int r)
    {
        return query(1, 0, n - 1, l, r);
    }
};

int main()
{

    int n;
    cin >> n;
    vector<ll> a(n, 0);
    vector<vector<ll>> queries;
    ll q;
    cin >> q;
    while (q--)
    {
        int l, r, val;
        cin >> l >> r >> val;
        queries.push_back({l - 1, r - 1, val});
    }
    vector<ll> sum(n, 0);
    for (int b = 0; b < 32; b++)
    {
        fill(sum.begin(), sum.end(), 0);
        for (auto c : queries)
        {
            ll l = c[0];
            ll r = c[1];
            ll val = c[2];
            if ((val >> b) & 1)
            {
                sum[l] += 1;
                if (r + 1 < n)
                {
                    sum[r + 1] -= 1;
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (i > 0)
                sum[i] += sum[i - 1];
            if (sum[i] > 0)
                a[i] |= (1 << b);
        }
    }
    SegmentTree st(n);
    st.build(a);
    bool ans = true;
    for (auto c : queries)
    {
        ll l = c[0];
        ll r = c[1];
        ll val = c[2];
        if (st.query(l, r) != val)
        {
            ans = false;
            break;
        }
    }
    if (ans)
    {
        cout << "YES" << endl;
        for (auto c : a)
            cout << c << " ";
        cout << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
}