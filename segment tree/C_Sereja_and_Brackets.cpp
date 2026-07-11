#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct Node
{
    int match, open, close;
    Node()
    {
        match = 0;
        open = 0;
        close = 0;
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
        int new_match = min(a.open, b.close);
        res.match = a.match + b.match + 2 * new_match;
        res.open = a.open + b.open - new_match;
        res.close = a.close + b.close - new_match;
        return res;
    }

    void build(string &s, int v, int tl, int tr)
    {
        if (tl == tr)
        {
            tree[v].open = (s[tl] == '(');
            tree[v].close = (s[tl] == ')');
            tree[v].match = 0;
            return;
        }
        int tm = (tl + tr) / 2;
        build(s, 2 * v, tl, tm);
        build(s, 2 * v + 1, tm + 1, tr);
        tree[v] = merge(tree[2 * v], tree[2 * v + 1]);
    }

    void update(int v, int tl, int tr, int pos, char c)
    {
        if (tl == tr)
        {
            tree[v].open = (c == '(');
            tree[v].close = (c == ')');
            tree[v].match = 0;
            return;
        }
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(2 * v, tl, tm, pos, c);
        else
            update(2 * v + 1, tm + 1, tr, pos, c);

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

    void build(string &s)
    {
        build(s, 1, 0, n - 1);
    }

    void update(int pos, char c)
    {
        update(1, 0, n - 1, pos, c);
    }

    ll query(int l, int r)
    {
        return query(1, 0, n - 1, l, r).match;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    int n = s.size();
    int q;
    cin >> q;
    SegmentTree st(n);
    st.build(s);
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        cout << st.query(l - 1, r - 1) << '\n';
    }
}