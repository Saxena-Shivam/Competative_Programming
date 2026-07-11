#include <bits\stdc++.h>
using namespace std;
class SegmentTree
{
    int n;
    vector<int> tree;
    vector<bool> lazy;
    vector<int> lazyVal;

public:
    SegmentTree() {};
    SegmentTree(int _n)
    {
        n = _n;
        tree.resize(4 * n);
        lazy.resize(4 * n);
        lazyVal.resize(4 * n);
    }
    void apply(int v, int tl, int tr, int val)
    {
        if (tl != tr)
        {
            lazy[v] = true;
            lazyVal[v] = val;
        }
        tree[v] = (tr - tl + 1) * val;
    }
    void pushDown(int v, int tl, int tr)
    {
        if (!lazy[v])
            return;
        lazy[v] = false;
        int tm = tl + (tr - tl) / 2;
        apply(2 * v, tl, tm, lazyVal[v]);
        apply(2 * v + 1, tm + 1, tr, lazyVal[v]);
        lazyVal[v] = 0;
    }
    void build(vector<int> &a, int v, int tl, int tr)
    {
        if (tl == tr)
        {
            tree[v] = a[tr];
            return;
        }
        int tm = tl + (tr - tl) / 2;
        build(a, 2 * v, tl, tm);
        build(a, 2 * v + 1, tm + 1, tr);
        tree[v] = tree[2 * v] + tree[2 * v + 1];
    }
    int query(int v, int tl, int tr, int l, int r)
    {
        if (tl > r || tr < l)
            return 0;
        if (tl >= l && tr <= r)
            return tree[v];
        pushDown(v, tl, tr);
        int tm = tl + (tr - tl) / 2;
        int left_sum = query(2 * v, tl, tm, l, r);
        int right_sum = query(2 * v + 1, tm + 1, tr, l, r);
        return left_sum + right_sum;
    }
    void update(int v, int tl, int tr, int l, int r, int val)
    {
        if (l <= tl && tr <= r)
        {
            apply(v, tl, tr, val);
            return;
        }
        if (l > tr || r < tl)
            return;
        pushDown(v, tl, tr);
        int tm = tl + (tr - tl) / 2;
        update(2 * v, tl, tm, l, r, val);
        update(2 * v + 1, tm + 1, tr, l, r, val);
        tree[v] = tree[2 * v] + tree[2 * v + 1];
    }
    // overloaded functions
    void build(vector<int> &a)
    {
        build(a, 1, 0, n - 1);
    }
    int query(int l, int r)
    {
        return query(1, 0, n - 1, l, r);
    }
    void update(int l, int r, int val)
    {
        update(1, 0, n - 1, l, r, val);
    }
};
int main()
{
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    SegmentTree st(n);
    st.build(a);
    while (q--)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int l, r, val;
            cin >> l >> r >> val;
            st.update(l, r, val);
        }
        else
        {
            int l, r;
            cin >> l >> r;
            cout << st.query(l, r) << endl;
        }
    }
}