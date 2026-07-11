#include <bits/stdc++.h>
using namespace std;
/* Segment Tree Lazy Propogation Code (Not Generic Code) */
#define ll long long
class SegTree
{
public:
    int n;
    vector<ll> t, unpropUpd;
    vector<bool> isLazy;
    SegTree() {}
    SegTree(int n)
    {
        this->n = n;
        t.resize(4 * n);
        isLazy.resize(4 * n);
        unpropUpd.resize(4 * n);
    }
    void apply(int v, int tl, int tr, ll val)
    {
        if (tl != tr)
        {
            isLazy[v] = true;
            unpropUpd[v] = max(unpropUpd[v], val);
        }
        t[v] = max(t[v], val);
    }

    void pushDown(int v, int tl, int tr)
    {
        if (!isLazy[v])
            return;
        isLazy[v] = false;
        int tm = (tl + tr) / 2;
        apply(2 * v, tl, tm, unpropUpd[v]);
        apply(2 * v + 1, tm + 1, tr, unpropUpd[v]);
        unpropUpd[v] = 0;
    }
    void build(vector<int> &a, int v, int tl, int tr)
    {
        if (tl == tr)
        {
            t[v] = a[tl];
            return;
        }
        int tm = (tl + tr) / 2;
        build(a, 2 * v, tl, tm);
        build(a, 2 * v + 1, tm + 1, tr);
        t[v] = max(t[2 * v], t[2 * v + 1]);
    }
    ll query(int v, int tl, int tr, int l, int r)
    {
        if (tl > r || tr < l)
            return LLONG_MIN;
        if (l <= tl && tr <= r)
            return t[v];
        pushDown(v, tl, tr);
        int tm = (tl + tr) / 2;
        ll leftAns = query(2 * v, tl, tm, l, r);
        ll rightAns = query(2 * v + 1, tm + 1, tr, l, r);
        return max(leftAns, rightAns);
    }
    void update(int v, int tl, int tr, int l, int r, ll val)
    {
        if (l <= tl && tr <= r)
        {
            apply(v, tl, tr, val);
            return;
        }
        if (tl > r || tr < l)
            return;
        pushDown(v, tl, tr);
        int tm = (tl + tr) / 2;
        update(2 * v, tl, tm, l, r, val);
        update(2 * v + 1, tm + 1, tr, l, r, val);
        t[v] = max(t[2 * v], t[2 * v + 1]);
    }
    void build(vector<int> &a)
    {
        build(a, 1, 0, n - 1);
    }
    ll query(int l, int r)
    {
        return query(1, 0, n - 1, l, r);
    }
    void update(int l, int r, ll val)
    {
        update(1, 0, n - 1, l, r, val);
    }
};

int main()
{

    int n;
    cin >> n;
    int q;
    cin >> q;
    vector<int> a(n, 0);
    SegTree segTree(n);
    segTree.build(a);
    while (q--)
    {
        int type;
        cin >> type;
        if (type == 2)
        {
            int ind;
            cin >> ind;
            cout << segTree.query(ind, ind) << endl;
        }
        else
        {
            int l, r;
            ll val;
            cin >> l >> r >> val;
            segTree.update(l, r - 1, val);
        }
    }
}
