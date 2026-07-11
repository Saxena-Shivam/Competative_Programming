#include <bits/stdc++.h>
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
        lazy.resize(4 * n, false);
        lazyVal.resize(4 * n, 0);
    }

    void apply(int v, int tl, int tr, int val)
    {
        if ((tr - tl + 1) % 2 == 0)
            tree[v] = 0;
        else
            tree[v] = val;

        if (tl != tr)
        {
            lazy[v] = true;
            lazyVal[v] = val;
        }
    }

    void pushDown(int v, int tl, int tr)
    {
        if (!lazy[v])
            return;

        int tm = tl + (tr - tl) / 2;
        apply(2 * v, tl, tm, lazyVal[v]);
        apply(2 * v + 1, tm + 1, tr, lazyVal[v]);

        lazy[v] = false;
    }

    void build(vector<int> &a, int v, int tl, int tr)
    {
        if (tl == tr)
        {
            tree[v] = a[tl];
            return;
        }
        int tm = tl + (tr - tl) / 2;
        build(a, 2 * v, tl, tm);
        build(a, 2 * v + 1, tm + 1, tr);
        tree[v] = tree[2 * v] ^ tree[2 * v + 1];
    }

    int query(int v, int tl, int tr, int l, int r)
    {
        if (tl > r || tr < l)
            return 0;

        if (tl >= l && tr <= r)
            return tree[v];

        pushDown(v, tl, tr);

        int tm = tl + (tr - tl) / 2;
        return query(2 * v, tl, tm, l, r) ^ query(2 * v + 1, tm + 1, tr, l, r);
    }

    void update(int v, int tl, int tr, int l, int r, int val)
    {
        if (tl > r || tr < l)
            return;

        if (tl >= l && tr <= r)
        {
            apply(v, tl, tr, val);
            return;
        }

        pushDown(v, tl, tr);

        int tm = tl + (tr - tl) / 2;
        update(2 * v, tl, tm, l, r, val);
        update(2 * v + 1, tm + 1, tr, l, r, val);

        tree[v] = tree[2 * v] ^ tree[2 * v + 1];
    }

    // wrappers
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

    SegmentTree segTree(n);
    segTree.build(a);

    while (q--)
    {
        int type;
        cin >> type;

        if (type == 1)
        {
            int l, r, val;
            cin >> l >> r >> val;
            segTree.update(l, r, val);
        }
        else
        {
            int l, r;
            cin >> l >> r;
            cout << segTree.query(l, r) << "\n";
        }
    }

    return 0;
}