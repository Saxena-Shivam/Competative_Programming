#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct Node
{
    ll sum, pref, suff, ans;
};

class SegmentTree
{
    int n;
    vector<Node> tree;

public:
    SegmentTree(int _n)
    {
        n = _n;
        tree.resize(4 * n);
    }

    Node make_node(ll val)
    {
        Node temp;
        temp.sum = val;
        temp.pref = temp.suff = temp.ans = max(val, 0LL);
        return temp;
    }

    Node merge(Node left, Node right)
    {
        Node res;
        res.sum = left.sum + right.sum;
        res.pref = max(left.pref, left.sum + right.pref);
        res.suff = max(right.suff, right.sum + left.suff);
        res.ans = max({left.ans, right.ans, left.suff + right.pref});
        return res;
    }

    void build(vector<int> &a, int v, int tl, int tr)
    {
        if (tl == tr)
        {
            tree[v] = make_node(a[tl]);
            return;
        }
        int tm = (tl + tr) / 2;
        build(a, 2 * v, tl, tm);
        build(a, 2 * v + 1, tm + 1, tr);
        tree[v] = merge(tree[2 * v], tree[2 * v + 1]);
    }

    Node query(int v, int tl, int tr, int l, int r)
    {
        if (l > r)
            return make_node(0);

        if (tl == l && tr == r)
            return tree[v];

        int tm = (tl + tr) / 2;

        Node left = query(2 * v, tl, tm, l, min(r, tm));
        Node right = query(2 * v + 1, tm + 1, tr, max(l, tm + 1), r);

        return merge(left, right);
    }

    void update(int v, int tl, int tr, int pos, int val)
    {
        if (tl == tr)
        {
            tree[v] = make_node(val);
            return;
        }
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(2 * v, tl, tm, pos, val);
        else
            update(2 * v + 1, tm + 1, tr, pos, val);

        tree[v] = merge(tree[2 * v], tree[2 * v + 1]);
    }

    // wrappers
    void build(vector<int> &a)
    {
        build(a, 1, 0, n - 1);
    }
    ll query(int l, int r)
    {
        return query(1, 0, n - 1, l, r).ans;
    }
    void update(int pos, int val)
    {
        update(1, 0, n - 1, pos, val);
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
    cout << st.query(0, n - 1) << endl;
    while (q--)
    {
        int pos, val;
        cin >> pos >> val;
        st.update(pos, val);
        cout << st.query(0, n - 1) << endl;
    }
}