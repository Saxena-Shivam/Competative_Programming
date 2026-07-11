// #include <bits\stdc++.h>
#include <iostream>
#include <vector>
#include <climits>
using namespace std;
#define ll long long
class SegmentTree
{
    int n;
    vector<int> tree;

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
            tree[v] = a[tr];
            return;
        }
        int tm = tl + (tr - tl) / 2;
        build(a, 2 * v, tl, tm);
        build(a, 2 * v + 1, tm + 1, tr);
        tree[v] = min(tree[2 * v], tree[2 * v + 1]);
    }
    int query(int v, int tl, int tr, int l, int r)
    {
        if (tl > r || tr < l)
            return INT_MAX;
        if (tl >= l && tr <= r)
            return tree[v];
        int tm = tl + (tr - tl) / 2;
        int left = query(2 * v, tl, tm, l, r);
        int right = query(2 * v + 1, tm + 1, tr, l, r);
        return min(left, right);
    }
    void update(int v, int tl, int tr, int id, int val)
    {
        if (tl == id && tr == id)
        {
            tree[v] = val;
            return;
        }
        if (id > tr || id < tl)
            return;
        int tm = tl + (tr - tl) / 2;
        update(2 * v, tl, tm, id, val);
        update(2 * v + 1, tm + 1, tr, id, val);
        tree[v] = min(tree[2 * v], tree[2 * v + 1]);
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
    void update(int id, int val)
    {
        update(1, 0, n - 1, id, val);
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

        int l, r;
        cin >> l >> r;
        cout << st.query(l - 1, r - 1) << endl;
    }
}