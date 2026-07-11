#include <bits/stdc++.h>
using namespace std;
/* Segment Tree Lazy Propogation Code (Not Generic Code) */
#define ll long long
struct Node
{
    ll max;
    ll sum;
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
    void build(vector<int> &a, int v, int tl, int tr)
    {
        if (tl == tr)
        {
            t[v].sum = a[tl];
            t[v].max = a[tl];
            return;
        }
        int tm = (tl + tr) / 2;
        build(a, 2 * v, tl, tm);
        build(a, 2 * v + 1, tm + 1, tr);
        t[v].sum = t[2 * v].sum + t[2 * v + 1].sum;
        t[v].max = max(t[2 * v].max, t[2 * v + 1].max);
    }
    Node query(int v, int tl, int tr, int l, int r)
    {
        if (tl > r || tr < l)
            return {0, 0};
        if (l <= tl && tr <= r)
            return t[v];
        int tm = (tl + tr) / 2;
        Node leftAns = query(2 * v, tl, tm, l, r);
        Node rightAns = query(2 * v + 1, tm + 1, tr, l, r);
        return {max(leftAns.max, rightAns.max), leftAns.sum + rightAns.sum};
    }
    void update_mod(int v, int tl, int tr, int l, int r, ll val)
    {
        if (tl > r || tr < l || t[v].max < val)
            return;
        if (tl == tr)
        {
            t[v].sum = t[v].sum % val;
            t[v].max = t[v].sum;
            return;
        }
        int tm = (tl + tr) / 2;
        if (l <= tm)
            update_mod(2 * v, tl, tm, l, r, val);
        if (r > tm)
            update_mod(2 * v + 1, tm + 1, tr, l, r, val);
        t[v].sum = t[2 * v].sum + t[2 * v + 1].sum;
        t[v].max = max(t[2 * v].max, t[2 * v + 1].max);
    }
    void update_point(int v, int tl, int tr, int k, ll val)
    {
        if (tl == tr)
        {
            t[v].sum = val;
            t[v].max = val;
            return;
        }
        int tm = (tl + tr) / 2;
        if (k <= tm)
            update_point(2 * v, tl, tm, k, val);
        else
            update_point(2 * v + 1, tm + 1, tr, k, val);
        t[v].sum = t[2 * v].sum + t[2 * v + 1].sum;
        t[v].max = max(t[2 * v].max, t[2 * v + 1].max);
    }
    void build(vector<int> &a)
    {
        build(a, 1, 0, n - 1);
    }
    ll query(int l, int r)
    {
        return query(1, 0, n - 1, l, r).sum;
    }
    void update_mod(int l, int r, ll val)
    {
        update_mod(1, 0, n - 1, l, r, val);
    }
    void update_point(int k, ll val)
    {
        update_point(1, 0, n - 1, k, val);
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
        else if (type == 2)
        {
            int l, r, x;
            cin >> l >> r >> x;
            segTree.update_mod(l - 1, r - 1, x);
        }
        else
        {
            int k;
            ll x;
            cin >> k >> x;
            segTree.update_point(k - 1, x);
        }
    }
}
