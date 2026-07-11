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
        tree[v] = max(tree[2 * v], tree[2 * v + 1]);
    }

    void update(int v, int tl, int tr, int pos, int val)
    {
        if (tl == tr)
        {
            tree[v] -= val;
            return;
        }
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(2 * v, tl, tm, pos, val);
        else
            update(2 * v + 1, tm + 1, tr, pos, val);

        tree[v] = max(tree[2 * v], tree[2 * v + 1]);
    }

    ll query(int v, int tl, int tr, int val)
    {
        if (tree[v] < val)
            return -1;
        if (tl == tr)
            return tl;
        int tm = (tl + tr) / 2;
        if (tree[2 * v] >= val)
            return query(2 * v, tl, tm, val);
        else
            return query(2 * v + 1, tm + 1, tr, val);
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

    void update(int pos, int val)
    {
        update(1, 0, n - 1, pos, val);
    }

    ll query(int val)
    {
        return query(1, 0, n - 1, val);
    }
};

int main()
{
    int n;
    cin >> n;
    ll q;
    cin >> q;
    vector<ll> a(q, 0);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    SegmentTree st(n);
    st.build(a);
    while (q--)
    {
        int val;
        cin >> val;
        ll ans = st.query(val);
        if (ans == -1)
        {
            cout << 0 << " ";
        }
        else
        {
            cout << ans + 1 << " ";
            st.update(ans, val);
        }
    }
    cout << endl;
}