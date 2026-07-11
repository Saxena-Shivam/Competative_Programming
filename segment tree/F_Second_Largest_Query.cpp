#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct Node
{
    int maxi, s_maxi, cnt1, cnt2;
};

class SegmentTree
{
private:
    vector<Node> tree;
    int n;
    Node merge(Node a, Node b)
    {
        vector<pair<int, int>> v;
        if (a.cnt1)
            v.push_back({a.maxi, a.cnt1});
        if (a.cnt2)
            v.push_back({a.s_maxi, a.cnt2});
        if (b.cnt1)
            v.push_back({b.maxi, b.cnt1});
        if (b.cnt2)
            v.push_back({b.s_maxi, b.cnt2});
        sort(v.begin(), v.end(), greater<>());
        Node res;
        res.maxi = v[0].first;
        res.cnt1 = 0;
        res.s_maxi = INT_MIN;
        res.cnt2 = 0;
        for (auto &p : v)
        {
            if (p.first == res.maxi)
                res.cnt1 += p.second;
            else
            {
                res.s_maxi = p.first;
                break;
            }
        }
        for (auto &p : v)
        {
            if (p.first == res.s_maxi)
                res.cnt2 += p.second;
        }
        return res;
    }
    void build(vector<int> &a, int v, int tl, int tr)
    {
        if (tl == tr)
        {
            tree[v] = {a[tl], INT_MIN, 1, 0};
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
            tree[v] = {val, INT_MIN, 1, 0};
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
            return {INT_MIN, INT_MIN, 0, 0};
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

    void build(vector<int> &a)
    {
        build(a, 1, 0, n - 1);
    }

    void update(int pos, int val)
    {
        update(1, 0, n - 1, pos, val);
    }

    ll query(int l, int r)
    {
        Node res = query(1, 0, n - 1, l, r);
        return res.cnt2;
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
            id--;
            st.update(id, val);
        }
        else
        {
            int l, r;
            cin >> l >> r;
            cout << st.query(l - 1, r - 1) << '\n';
        }
    }
}