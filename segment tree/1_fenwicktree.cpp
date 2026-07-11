#include <bits/stdc++.h>
using namespace std;
class FenWick
{
    int n;
    vector<int> bit;

public:
    FenWick(int n)
    {
        bit.assign(n + 1, 0);
        this->n = n;
    }
    void update(int id, int val)
    {
        while (id <= n)
        {
            bit[id] += val;
            id += (id & -id);
        }
    }
    long long query(int id)
    {
        long long sum = 0;
        while (id > 0)
        {
            sum += bit[id];
            id -= (id & -id);
        }
        return sum;
    }
};