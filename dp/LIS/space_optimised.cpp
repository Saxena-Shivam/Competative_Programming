#include <bits\stdc++.h>
using namespace std;
class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(n, 1);
        int ans = 1, maxi = 1;
        for (int i = 0; i < n; i++)
        {
            maxi = 1;
            for (int j = 0; j < i; j++)
            {
                if (nums[i] > nums[j])
                {
                    maxi = max(maxi, dp[i] + dp[j]);
                }
            }
            dp[i] = maxi;
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};