#include <bits\stdc++.h>
using namespace std;
// This method is used only for finding length
class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> temp;
        temp.push_back(nums[0]);
        for (int i = 0; i < n; i++)
        {
            if (temp.back() < nums[i])
                temp.push_back(nums[i]);
            else
            {
                int ind = lower_bound(temp.begin(), temp.end(), nums[i]) - temp.begin();
                temp[ind] = nums[i];
            }
        }
        return temp.size();
    }
};