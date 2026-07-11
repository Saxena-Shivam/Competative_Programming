#include <bits/stdc++.h>
using namespace std;
#define ll long long

class ST
{
    int n;
    vector<ll> t;

public:
    ST(int _n)
    {
        n = _n;
        t.resize(4 * n);
    }
    void build(vector<ll> &a, int v, int tl, int tr)
    {
        if (tl == tr)
        {
            t[v] = a[tl];
            return;
        }
        int tm = (tl + tr) / 2;
        build(a, 2 * v, tl, tm);
        build(a, 2 * v + 1, tm + 1, tr);
        t[v] = min(t[2 * v], t[2 * v + 1]);
    }
    void upd(int v, int tl, int tr, int pos, ll val)
    {
        if (tl == tr)
        {
            t[v] = val;
            return;
        }
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            upd(2 * v, tl, tm, pos, val);
        else
            upd(2 * v + 1, tm + 1, tr, pos, val);
        t[v] = min(t[2 * v], t[2 * v + 1]);
    }

    ll query(int v, int tl, int tr, int l, int r)
    {
        if (tl > r || tr < l)
            return 1e18;
        if (l <= tl && tr <= r)
            return t[v];
        int tm = (tl + tr) / 2;
        return min(query(2 * v, tl, tm, l, r),
                   query(2 * v + 1, tm + 1, tr, l, r));
    }

    void build(vector<ll> &a)
    {
        build(a, 1, 0, n - 1);
    }
    void update(int pos, ll val)
    {
        upd(1, 0, n - 1, pos, val);
    }
    ll query(int l, int r)
    {
        return query(1, 0, n - 1, l, r);
    }
};

int main()
{
    int n, q;
    cin >> n >> q;
    vector<ll> p(n);
    for (int i = 0; i < n; i++)
        cin >> p[i];
    vector<ll> a(n), b(n);
    for (int i = 0; i < n; i++)
    {
        a[i] = p[i] + (i + 1);
        b[i] = p[i] - (i + 1);
    }
    ST st1(n), st2(n);
    st1.build(a);
    st2.build(b);
    while (q--)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int k;
            ll x;
            cin >> k >> x;
            k--;
            st1.update(k, x + (k + 1));
            st2.update(k, x - (k + 1));
        }
        else
        {
            int k;
            cin >> k;
            k--;
            ll left = st2.query(0, k);
            ll right = st1.query(k, n - 1);
            cout << min(left + (k + 1), right - (k + 1)) << "\n";
        }
    }
}