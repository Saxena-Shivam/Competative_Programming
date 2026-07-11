#include <bits\stdc++.h>
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
            tree[v] = a[tl];
            return;
        }
        int tm = tl + (tr - tl) / 2;
        build(a, 2 * v, tl, tm);
        build(a, 2 * v + 1, tm + 1, tr);
        tree[v] = tree[2 * v] + tree[2 * v + 1];
    }
    ll query(int v, int tl, int tr, int l, int r)
    {
        if (tl > r || tr < l)
            return 0;
        if (tl >= l && tr <= r)
            return tree[v];
        int tm = tl + (tr - tl) / 2;
        ll left_sum = query(2 * v, tl, tm, l, r);
        ll right_sum = query(2 * v + 1, tm + 1, tr, l, r);
        return left_sum + right_sum;
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
        tree[v] = tree[2 * v] + tree[2 * v + 1];
    }
    // overloaded functions
    void build(vector<int> &a)
    {
        build(a, 1, 0, n - 1);
    }
    ll query(int l, int r)
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
    cin >> n;
    vector<int> a(n + 1, 0);
    SegmentTree st(n + 1);
    st.build(a);
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        a[x] = 1;
        cout << st.query(x + 1, n) << " ";
        st.update(x, 1);
    }
}