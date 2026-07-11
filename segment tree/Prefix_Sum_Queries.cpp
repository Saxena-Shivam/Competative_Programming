#include <bits/stdc++.h>
using namespace std;
#define ll long long
struct Node
{
    ll sum = 0, prefsum = -1e15;
};
class SegmentTree
{
private:
    vector<Node> tree;
    int n;
    Node merge(Node &a, Node &b)
    {
        Node res;
        res.sum = a.sum + b.sum;
        res.prefsum = max(a.prefsum, a.sum + b.prefsum);
        return res;
    }
    void build(vector<ll> &a, int v, int tl, int tr)
    {
        if (tl == tr)
        {
            tree[v].prefsum = a[tl];
            tree[v].sum = a[tl];
            return;
        }
        int tm = (tl + tr) / 2;
        build(a, 2 * v, tl, tm);
        build(a, 2 * v + 1, tm + 1, tr);
        tree[v] = merge(tree[2 * v], tree[2 * v + 1]);
    }

    void update(int v, int tl, int tr, int pos, int val)
    {
        if (tl == tr)
        {
            tree[v].prefsum = val;
            tree[v].sum = val;
            return;
        }
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(2 * v, tl, tm, pos, val);
        else
            update(2 * v + 1, tm + 1, tr, pos, val);

        tree[v] = merge(tree[2 * v], tree[2 * v + 1]);
    }

    Node query(int v, int tl, int tr, int l, int r)
    {
        if (tl > r || tr < l)
            return Node();
        if (tl >= l && tr <= r)
            return tree[v];
        int tm = tl + (tr - tl) / 2;
        Node left_sum = query(2 * v, tl, tm, l, r);
        Node right_sum = query(2 * v + 1, tm + 1, tr, l, r);
        return merge(left_sum, right_sum);
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

    ll query(ll l, ll r)
    {
        return query(1, 0, n - 1, l, r).prefsum;
    }
};

int main()
{
    int n;
    cin >> n;
    ll q;
    cin >> q;
    vector<ll> a(n, 0);
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
            id--;
            a[id] = val;
            st.update(id, val);
        }
        else
        {
            int l, r;
            cin >> l >> r;
            cout << max(0LL, st.query(l - 1, r - 1)) << endl;
        }
    }
}