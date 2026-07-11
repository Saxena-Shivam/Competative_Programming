#include <bits/stdc++.h>
using namespace std;
#define ll long long

class SegmentTree
{
private:
    vector<vector<ll>> tree;
    int n;
    vector<ll> merge(vector<ll> &a, vector<ll> &b)
    {
        vector<ll> f(26, 0);
        for (int i = 0; i < 26; i++)
        {
            f[i] = a[i] + b[i];
        }
        return f;
    }
    void build(string &s, int v, int tl, int tr)
    {
        if (tl == tr)
        {
            tree[v] = vector<ll>(26, 0);
            tree[v][s[tl] - 'a'] = 1;
            return;
        }
        int tm = (tl + tr) / 2;
        build(s, 2 * v, tl, tm);
        build(s, 2 * v + 1, tm + 1, tr);
        tree[v] = merge(tree[2 * v], tree[2 * v + 1]);
    }

    void update(int v, int tl, int tr, int pos, char c)
    {
        if (tl == tr)
        {
            tree[v] = vector<ll>(26, 0);
            tree[v][c - 'a'] = 1;
            return;
        }
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(2 * v, tl, tm, pos, c);
        else
            update(2 * v + 1, tm + 1, tr, pos, c);
        tree[v] = merge(tree[2 * v], tree[2 * v + 1]);
    }

    vector<ll> query(int v, int tl, int tr, int l, int r)
    {
        if (tl > r || tr < l)
            return vector<ll>(26, 0);
        if (tl >= l && tr <= r)
            return tree[v];
        int tm = (tl + tr) / 2;
        vector<ll> left = query(2 * v, tl, tm, l, r);
        vector<ll> right = query(2 * v + 1, tm + 1, tr, l, r);
        return merge(left, right);
    }

public:
    SegmentTree(int _n)
    {
        n = _n;
        tree.resize(4 * n, vector<ll>(26, 0));
    }

    void build(string &s)
    {
        build(s, 1, 0, n - 1);
    }

    void update(int pos, char c)
    {
        update(1, 0, n - 1, pos, c);
    }

    ll query(int l, int r)
    {
        vector<ll> res = query(1, 0, n - 1, l, r);
        ll ans = 0;
        for (int i = 0; i < 26; i++)
            if (res[i] > 0)
                ans++;
        return ans;
    }
};

int main()
{

    string s;
    cin >> s;
    int n = s.size();
    int q;
    cin >> q;
    SegmentTree st(n);
    st.build(s);
    while (q--)
    {
        int type;
        cin >> type;

        if (type == 1)
        {
            int id;
            char c;
            cin >> id >> c;
            id--;
            st.update(id, c);
        }
        else
        {
            int l, r;
            cin >> l >> r;
            cout << st.query(l - 1, r - 1) << '\n';
        }
    }
}