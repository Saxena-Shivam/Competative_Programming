#include <iostream>
#include <vector>
using namespace std;
class Fenwick
{
    int n;
    vector<int> bits;

public:
    Fenwick(int n)
    {
        this->n = n;
        bits.resize(n + 1, 0);
    }
    void update(int i, int val)
    {
        while (i <= n)
        {
            bits[i] += val;
            i += i & (-i);
        }
    }
    long long query(int i)
    {
        long long sum = 0;
        while (i > 0)
        {
            sum += bits[i];
            i -= i & (-i);
        }
        return sum;
    }
};
class NumArray
{
public:
    vector<int> a;
    Fenwick f;
    NumArray(vector<int> &nums) : f(nums.size())
    {
        int n = nums.size();
        a = nums;
        for (int i = 0; i < n; i++)
        {
            f.update(i + 1, nums[i]);
        }
    }
    void update(int index, int val)
    {
        f.update(index + 1, -a[index]);
        f.update(index + 1, val);
        a[index] = val;
    }
    int sumRange(int left, int right)
    {
        return f.query(right + 1) - f.query(left);
    }
};
int main()
{
    //[ "NumArray", "sumRange", "update", "sumRange" ]
    // [[[ 1, 3, 5 ]], [ 0, 2 ], [ 1, 2 ], [ 0, 2 ]]
    vector<int> nums = {1, 3, 5};
    NumArray numArray(nums);
    vector<pair<string, vector<int>>> operations = {{"sumRange", {0, 2}}, {"update", {1, 2}}, {"sumRange", {0, 2}}};
    for (auto &op : operations)
    {
        if (op.first == "sumRange")
        {
            cout << numArray.sumRange(op.second[0], op.second[1]) << endl;
        }
        else if (op.first == "update")
        {
            numArray.update(op.second[0], op.second[1]);
        }
    }
}