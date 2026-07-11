#include <bits/stdc++.h>
using namespace std;
/* Segment Tree Lazy Propogation Code (Not Generic Code) */
class SegTree
{
public:
    int len;
    vector<int> t, unpropUpd;
    vector<bool> isLazy;
    SegTree() {}
    SegTree(int l)
    {
        len = l;
        t.resize(4 * len);
        isLazy.resize(4 * len);
        unpropUpd.resize(4 * len);
    }
    void apply(int v, int tl, int tr, int val)
    {
        if (tl != tr)
        {
            isLazy[v] = true;
            unpropUpd[v] = val;
        }
        t[v] = (tr - tl + 1) * val;
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
        t[v] = t[2 * v] + t[2 * v + 1];
    }
    int query(int v, int tl, int tr, int l, int r)
    {
        if (tl > r || tr < l)
            return 0;
        if (l <= tl && tr <= r)
            return t[v];
        pushDown(v, tl, tr);
        int tm = (tl + tr) / 2;
        int leftAns = query(2 * v, tl, tm, l, r);
        int rightAns = query(2 * v + 1, tm + 1, tr, l, r);
        return leftAns + rightAns;
    }
    void update(int v, int tl, int tr, int l, int r, int val)
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

    void update(int l, int r, int val)
    {
        update(1, 0, len - 1, l, r, val);
    }
};

int main()
{

    int n = 8;
    vector<int> a = {1, 2, 1, 4, 2, 3, 1, 1};

    SegTree segTree(n);
    segTree.build(a);

    // Build - View Build Data
    for (int i = 0; i < n; i++)
    {
        cout << segTree.query(i, i) << " ";
    }
    cout << endl;

    // Query - Range Query
    int sum = segTree.query(1, 5);
    cout << "Sum for range id = 1 to id = 5 is: " << sum << endl;

    // Update - Point Update
    segTree.update(2, 2, 10); // at id=2 [i.e. l=2, r=2],make the value = 10
    sum = segTree.query(1, 5);
    cout << "New Sum for range id = 1 to id = 5 is: " << sum << endl;

    for (int i = 0; i < n; i++)
    {
        cout << segTree.query(i, i) << " ";
    }
    cout << endl
         << endl;

    segTree.update(2, 7, 10);
    segTree.update(2, 7, 20);
    for (int i = 0; i < n; i++)
    {
        cout << segTree.query(i, i) << " ";
    }
    cout << endl;

    sum = segTree.query(2, 3);
    cout << "New Sum for range l = 2 to r = 3 is: " << sum << endl;
}
