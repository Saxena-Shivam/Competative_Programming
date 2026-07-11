#include <bits/stdc++.h>
using namespace std;
/* Segment Tree Lazy Propogation Code (Not Generic Code) */
#define ll long long
struct Node
{
    ll maxi;
    ll sum;
    ll pref;
    ll suff;
};
class SegTree
{
public:
    int n;
    vector<Node> t;
    SegTree() {}
    SegTree(int n)
    {
        this->n = n;
        t.resize(4 * n);
    }
    Node merge(Node &L, Node &R)
    {
        Node res;
        res.sum = L.sum + R.sum;
        res.maxi = max(L.maxi, R.maxi);
        res.pref = max(L.pref, L.sum + R.pref);
        res.suff = max(R.suff, R.sum + L.suff);
        return res;
    }
    void build(vector<int> &a, int v, int tl, int tr)
    {
        if (tl == tr)
        {
            t[v].sum = a[tl];
            t[v].maxi = a[tl];
            t[v].pref = a[tl];
            t[v].suff = a[tl];
            return;
        }
        int tm = (tl + tr) / 2;
        build(a, 2 * v, tl, tm);
        build(a, 2 * v + 1, tm + 1, tr);
        t[v] = merge(t[2 * v], t[2 * v + 1]);
    }
    Node query(int v, int tl, int tr, int l, int r)
    {
        return t[1];
    }
    void update(int v, int tl, int tr, int l, int r, ll val)
    {
        if (tl > r || tr < l || t[v].maxi < val)
            return;
        if (tl == tr)
        {
            t[v].sum = t[v].sum % val;
            t[v].maxi = t[v].sum;
            return;
        }
        int tm = (tl + tr) / 2;
        if (l <= tm)
            update(2 * v, tl, tm, l, r, val);
        if (r > tm)
            update(2 * v + 1, tm + 1, tr, l, r, val);
        t[v] = merge(t[2 * v], t[2 * v + 1]);
    }
    void build(vector<int> &a)
    {
        build(a, 1, 0, n - 1);
    }
    ll query(int l, int r)
    {
        return query(1, 0, n - 1, l, r).maxi;
    }
    void update(int l, int r, ll val)
    {
        update(1, 0, n - 1, l, r, val);
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    int q;
    cin >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    SegTree segTree(n);
    segTree.build(a);
    while (q--)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int l, r;
            cin >> l >> r;
            cout << segTree.query(l - 1, r - 1) << endl;
        }
        else
        {
            int l, r, x;
            cin >> l >> r >> x;
            segTree.update(l - 1, r - 1, x);
        }
    }
}
