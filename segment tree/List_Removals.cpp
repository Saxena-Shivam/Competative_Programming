#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define ll long long

class SegmentTree
{
    int n;
    vector<ll> tree;

public:
    SegmentTree() {};
    SegmentTree(int _n)
    {
        n = _n;
        tree.resize(4 * n);
    }
    void build(vector<int> &a, int v, int tl, int tr)
    {
        if (tl == tr)
        {
            tree[v] = 1;
            return;
        }
        int tm = tl + (tr - tl) / 2;
        build(a, 2 * v, tl, tm);
        build(a, 2 * v + 1, tm + 1, tr);
        tree[v] = (tree[2 * v] + tree[2 * v + 1]);
    }
    void update(int v, int tl, int tr, int pos)
    {
        if (tl == tr)
        {
            tree[v] = 0;
            return;
        }
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(2 * v, tl, tm, pos);
        else
            update(2 * v + 1, tm + 1, tr, pos);
        tree[v] = (tree[2 * v] + tree[2 * v + 1]);
    }
    int query(int v, int tl, int tr, int val)
    {
        if (tl == tr)
            return tl;
        int tm = tl + (tr - tl) / 2;
        if (val <= tree[2 * v])
            return query(2 * v, tl, tm, val);
        else
            return query(2 * v + 1, tm + 1, tr, val - tree[2 * v]);
    }
    void build(vector<int> &a)
    {
        build(a, 1, 0, n - 1);
    }
    void update(int pos)
    {
        update(1, 0, n - 1, pos);
    }
    int query(int val)
    {
        return query(1, 0, n - 1, val);
    }
};

int main()
{
    int n, q;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    q = n;
    SegmentTree st(n);
    st.build(a);
    while (q--)
    {
        ll val;
        cin >> val;
        ll ans = st.query(val);
        cout << a[ans] << " ";
        st.update(ans);
    }
}