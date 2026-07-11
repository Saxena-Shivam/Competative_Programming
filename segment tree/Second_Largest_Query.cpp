#include <iostream>
#include <vector>
#include <unordered_map>
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
    ll n;

public:
    SegmentTree() {};
    SegmentTree(int _n)
    {
        n = _n;
        tree.resize(4 * n);
    }
    Node merge(Node t1, Node t2)
    {
        unordered_map<int, int> mp;
        mp[t1.maxi] += t1.cnt1;
        mp[t1.s_maxi] += t1.cnt2;
        mp[t2.maxi] += t2.cnt1;
        mp[t2.s_maxi] += t2.cnt2;
        int maxi = INT_MIN, s_maxi = INT_MIN;
        for (auto c : mp)
        {
            if (c.first > maxi)
            {
                s_maxi = maxi;
                maxi = c.first;
            }
            else if (c.first > s_maxi && c.first != maxi)
            {
                s_maxi = c.first;
            }
        }
        Node res;
        res.maxi = maxi;
        res.cnt1 = mp[maxi];
        if (s_maxi == INT_MIN)
        {
            res.s_maxi = INT_MIN;
            res.cnt2 = 0;
        }
        else
        {
            res.s_maxi = s_maxi;
            res.cnt2 = mp[s_maxi];
        }
        return res;
    }
    void build(vector<int> &a, int v, int tl, int tr)
    {
        if (tl == tr)
        {
            tree[v].maxi = a[tl];
            tree[v].s_maxi = a[tl];
            tree[v].cnt1 = 1;
            tree[v].cnt2 = 1;
        }
        ll tm = tl + (tr - tl) / 2;
        build(a, 2 * v, tl, tm);
        build(a, 2 * v + 1, tm + 1, tr);
        tree[v] = merge(tree[2 * v], tree[2 * v + 1]);
    }
    void update(int v, int tl, int tr, int id, ll val)
    {
        if (tl == tr)
        {
            tree[v].maxi = val;
            tree[v].s_maxi = val;
            tree[v].cnt1 = 1;
            tree[v].cnt2 = 1;
            return;
        }
        int tm = (tl + tr) / 2;
        if (id <= tm)
            update(2 * v, tl, tm, id, val);
        else
            update(2 * v + 1, tm + 1, tr, id, val);
        tree[v] = merge(tree[2 * v], tree[2 * v + 1]);
    }
    ll query(int v, int tl, int tr, int l, int r)
    {
        if (tl > r || tr < l)
            return 0;
        if (tl >= l && tr <= r)
        {
            return tree[v].cnt2;
        }
        int tm = tl + (tr - tl) / 2;
        return query(2 * v, tl, tm, l, r) +
               query(2 * v + 1, tm + 1, tr, l, r);
    }
    void build(vector<int> &a)
    {
        build(a, 1, 0, n - 1);
    }
    ll query(int l, int r)
    {
        return query(1, 0, n - 1, l, r);
    }
    void update(int id, int val)
    {
        update(1, 0, n - 1, id, val);
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
            a[id] = val;
            st.update(id, val);
        }
        else
        {
            int l, r;
            cin >> l >> r;
            cout << st.query(l - 1, r - 1) << endl;
        }
    }
}