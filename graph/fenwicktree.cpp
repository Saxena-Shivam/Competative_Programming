#include <bits/stdc++.h>
using namespace std;

class FenWick
{
public:
    int n;
    vector<int> bit;
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
class NumArray
{
public:
    NumArray(vector<int> &nums)
    {
        int n = nums.size();
        FenWick f(n);
        for (int i = 0; i < nums.size(); i++)
        {
            f.update(i + 1, nums[i]);
        }
    }
    void update(int index, int val)
    {
        f.update(index + 1, val);
    }
    int sumRange(int left, int right)
    {
        return f.query(right + 1) - f.query(left);
    }
};