#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct Node
{
    int g, cnt;
    Node()
    {
        g = 0;
        cnt = 0;
    }
};

class SegmentTree
{
private:
    vector<Node> tree;
    int n;

    Node merge(Node &a, Node &b)
    {
        Node res;
        res.g = __gcd(a.g, b.g);
        res.cnt = 0;
        if (res.g == a.g)
            res.cnt += a.cnt;
        if (res.g == b.g)
            res.cnt += b.cnt;
        return res;
    }

    void build(vector<ll> &a, int v, int tl, int tr)
    {
        if (tl == tr)
        {
            tree[v].g = a[tl];
            tree[v].cnt = 1;
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
            tree[v].g = val;
            tree[v].cnt = 1;
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
        {
            return Node();
        }
        if (tl >= l && tr <= r)
            return tree[v];

        int tm = (tl + tr) / 2;
        Node left = query(2 * v, tl, tm, l, r);
        Node right = query(2 * v + 1, tm + 1, tr, l, r);
        return merge(left, right);
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

    void update(int pos, char c)
    {
        update(1, 0, n - 1, pos, c);
    }

    ll query(int l, int r)
    {
        return query(1, 0, n - 1, l, r).cnt;
    }
};

int main()
{

    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int q;
    cin >> q;
    SegmentTree st(n);
    st.build(a);
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        cout << r - l + 1 - st.query(l - 1, r - 1) << '\n';
    }
}