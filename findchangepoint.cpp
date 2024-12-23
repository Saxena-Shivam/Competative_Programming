#include <iostream>
#include <vector>
using namespace std;

int findChangePoint(vector<int> &nums)
{
    int n = nums.size();
    int l = 0, h = n - 1;
    while (l < h)
    {
        int mid = l + (h - l) / 2;
        if (nums[mid] > nums[h])
        {
            l = mid + 1;
        }
        else
        {
            h = mid;
        }
    }
    return l;
}
int main()
{
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    cout << findChangePoint(nums);
    return 0;
}