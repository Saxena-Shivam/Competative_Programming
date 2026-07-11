#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct Node
{
    vector<ll> a, pref;
};

class SegmentTree
{
    vector<Node> tree;
    int n;

public:
    SegmentTree(int _n)
    {
        n = _n;
        tree.resize(4 * n);
    }

    Node combine(Node &L, Node &R)
    {
        Node res;
        std::merge(L.a.begin(), L.a.end(),
                   R.a.begin(), R.a.end(),
                   back_inserter(res.a));
        int sz = res.a.size();
        res.pref.resize(sz);
        res.pref[0] = res.a[0];
        for (int i = 1; i < sz; i++)
            res.pref[i] = res.pref[i - 1] + res.a[i];

        return res;
    }
    void build(vector<ll> &a, int v, int tl, int tr)
    {
        if (tl == tr)
        {
            tree[v].a = {a[tl]};
            tree[v].pref = {a[tl]};
            return;
        }
        int tm = (tl + tr) / 2;
        build(a, 2 * v, tl, tm);
        build(a, 2 * v + 1, tm + 1, tr);
        tree[v] = combine(tree[2 * v], tree[2 * v + 1]);
    }
    void build(vector<ll> &a)
    {
        build(a, 1, 0, n - 1);
    }
    ll getSum(int v, int tl, int tr, int l, int r, int &k)
    {
        if (tl > r || tr < l || k == 0)
            return 0;

        if (tl >= l && tr <= r)
        {
            int take = min((int)tree[v].a.size(), k);
            ll sum = tree[v].pref[take - 1];
            k -= take;
            return sum;
        }

        int tm = (tl + tr) / 2;
        ll left = getSum(2 * v, tl, tm, l, r, k);
        ll right = getSum(2 * v + 1, tm + 1, tr, l, r, k);
        return left + right;
    }

    bool can(int l, int r, int k, ll val)
    {
        int kk = k;
        ll sum = getSum(1, 0, n - 1, l, r, kk);
        return sum <= val;
    }

    ll query(int l, int r, ll val)
    {
        int low = 0, high = r - l + 1, ans = 0;

        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (can(l, r, mid, val))
            {
                ans = mid;
                low = mid + 1;
            }
            else
                high = mid - 1;
        }
        return ans;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    int q;
    cin >> q;

    vector<ll> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    SegmentTree st(n);
    st.build(a);

    while (q--)
    {
        ll x, val;
        cin >> x >> val;
        cout << st.query(0, x - 1, val) << "\n";
    }
}