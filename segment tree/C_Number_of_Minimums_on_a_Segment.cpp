#include <bits\stdc++.h>
using namespace std;
#define ll long long
class SegmentTree
{
    int n;
    vector<pair<int, int>> tree;

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
            tree[v] = {a[tr], 1};
            return;
        }
        int tm = tl + (tr - tl) / 2;
        build(a, 2 * v, tl, tm);
        build(a, 2 * v + 1, tm + 1, tr);
        int mini = min(tree[2 * v].first, tree[2 * v + 1].first);
        int f = (tree[2 * v].first == tree[2 * v + 1].first)
                    ? (tree[2 * v].second + tree[2 * v + 1].second)
                    : (tree[2 * v].first < tree[2 * v + 1].first
                           ? tree[2 * v].second
                           : tree[2 * v + 1].second);
        tree[v] = {mini, f};
    }
    pair<int, int> query(int v, int tl, int tr, int l, int r)
    {
        if (tl > r || tr < l)
            return {INT_MAX, 0};
        if (tl >= l && tr <= r)
            return tree[v];
        int tm = tl + (tr - tl) / 2;
        pair<int, int> left = query(2 * v, tl, tm, l, r);
        pair<int, int> right = query(2 * v + 1, tm + 1, tr, l, r);
        int mini = min(left.first, right.first);
        int f = (left.first == right.first)
                    ? (left.second + right.second)
                    : (left.first < right.first
                           ? left.second
                           : right.second);

        return {mini, f};
    }
    void update(int v, int tl, int tr, int id, int val)
    {
        if (tl == id && tr == id)
        {
            tree[v] = {val, 1};
            return;
        }
        if (id > tr || id < tl)
            return;
        int tm = tl + (tr - tl) / 2;
        update(2 * v, tl, tm, id, val);
        update(2 * v + 1, tm + 1, tr, id, val);
        int mini = min(tree[2 * v].first, tree[2 * v + 1].first);
        int f = (tree[2 * v].first == tree[2 * v + 1].first)
                    ? (tree[2 * v].second + tree[2 * v + 1].second)
                    : (tree[2 * v].first < tree[2 * v + 1].first
                           ? tree[2 * v].second
                           : tree[2 * v + 1].second);
        tree[v] = {mini, f};
    }
    // overloaded functions
    void build(vector<int> &a)
    {
        build(a, 1, 0, n - 1);
    }
    pair<int, int> query(int l, int r)
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
        int type;
        cin >> type;
        if (type == 1)
        {
            int id, val;
            cin >> id >> val;
            a[id] = val;
            st.update(id, val);
        }
        else
        {
            int l, r;
            cin >> l >> r;
            auto ans = st.query(l, r - 1);
            cout << ans.first << " " << ans.second << endl;
        }
    }
}