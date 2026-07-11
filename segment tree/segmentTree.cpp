#include <bits/stdc++.h>
using namespace std;
/* Segment Tree Standard Code (Without Lazy) */
class SegTree
{
public:
    int len;
    vector<int> t;

    SegTree() {}
    SegTree(int l)
    {
        len = l;
        t.resize(4 * len);
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
        t[v] = t[2 * v] + t[2 * v + 1];
    }
    int query(int v, int tl, int tr, int l, int r)
    {
        if (tl > r || tr < l)
            return 0;
        if (l <= tl && tr <= r)
            return t[v];
        int tm = (tl + tr) / 2;
        int leftAns = query(2 * v, tl, tm, l, r);
        int rightAns = query(2 * v + 1, tm + 1, tr, l, r);
        return leftAns + rightAns;
    }
    void update(int v, int tl, int tr, int id, int val)
    {
        if (tl == id && tr == id)
        {
            t[v] = val;
            return;
        }
        if (id > tr || id < tl)
            return;

        int tm = (tl + tr) / 2;
        update(2 * v, tl, tm, id, val);
        update(2 * v + 1, tm + 1, tr, id, val);
        t[v] = t[2 * v] + t[2 * v + 1];
    }
    void build(vector<int> &a)
    {
        build(a, 1, 0, len - 1);
    }

    int query(int l, int r)
    {
        return query(1, 0, len - 1, l, r);
    }

    void update(int id, int val)
    {
        update(1, 0, len - 1, id, val);
    }
};

int main()
{
    int n = 8;
    vector<int> a = {1, 2, 1, 4, 2, 3, 1, 1};

    SegTree segTree(n);
    segTree.build(a);
    for (int i = 0; i < n; i++)
    {
        cout << segTree.query(i, i) << " ";
    }
    cout << endl;
    int sum = segTree.query(1, 5);
    cout << "Sum for range id = 1 to id = 5 is: " << sum << endl;
    segTree.update(2, 10);
    sum = segTree.query(1, 5);
    cout << "New Sum for range id = 1 to id = 5 is: " << sum << endl;
}