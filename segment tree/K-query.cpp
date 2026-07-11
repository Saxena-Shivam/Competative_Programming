#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define ll long long

class SegmentTree
{
    int n;
    vector<vector<ll>> tree;

public:
    SegmentTree() {};
    SegmentTree(int _n)
    {
        n = _n;
        tree.resize(4 * n);
    }
    vector<ll> merge(vector<ll> &l, vector<ll> &r)
    {
        int i = 0, j = 0;
        int n = l.size(), m = r.size();
        vector<ll> ans;
        while (i < n && j < m)
        {
            if (l[i] < r[j])
            {
                ans.push_back(l[i]);
                i++;
            }
            else
            {
                ans.push_back(r[j]);
                j++;
            }
        }
        while (i < n)
            ans.push_back(l[i]), i++;
        while (j < m)
            ans.push_back(r[j]), j++;
        return ans;
    }

    void build(vector<int> &a, int v, int tl, int tr)
    {
        if (tl == tr)
        {
            tree[v].push_back({a[tl]});
            return;
        }
        int tm = tl + (tr - tl) / 2;
        build(a, 2 * v, tl, tm);
        build(a, 2 * v + 1, tm + 1, tr);
        tree[v] = merge(tree[2 * v], tree[2 * v + 1]);
    }
    int query(int v, int tl, int tr, int l, int r, int val)
    {
        if (tl > r || tr < l)
            return 0;
        if (tl >= l && tr <= r)
        {
            int total = tree[v].size();
            int ind = upper_bound(tree[v].begin(), tree[v].end(), val) - tree[v].begin();
            return total - ind;
        }

        int tm = tl + (tr - tl) / 2;
        return query(2 * v, tl, tm, l, r, val) +
               query(2 * v + 1, tm + 1, tr, l, r, val);
    }
    void build(vector<int> &a)
    {
        build(a, 1, 0, n - 1);
    }
    int query(int l, int r, int val)
    {
        return query(1, 0, n - 1, l, r, val);
    }
};

int main()
{
    int n, q;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cin >> q;
    SegmentTree st(n);
    st.build(a);
    while (q--)
    {
        int l, r, val;
        cin >> l >> r >> val;
        cout << st.query(l - 1, r - 1, val) << endl;
    }
}