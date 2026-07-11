#include <bits\stdc++.h>
using namespace std;
class Solution
{
public:
    int solve(vector<int> &nums, int i, int p, vector<vector<int>> &dp)
    {
        int n = nums.size();
        if (i == n || p == n)
            return 0;
        if (dp[i][p + 1] != -1)
            return dp[i][p + 1];
        if (p == -1 || nums[p] < nums[i])
        {
            return dp[i][p + 1] = max(1 + solve(nums, i + 1, i, dp), solve(nums, i + 1, p, dp));
        }
        else
        {
            return dp[i][p + 1] = solve(nums, i + 1, p, dp);
        }
    }
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> prev(n + 1, 0), cur(n + 1, 0);
        for (int i = n - 1; i >= 0; i--)
        {
            for (int p = i - 1; p >= -1; p--)
            {
                int len = prev[p + 1];
                if (p == -1 || nums[p] < nums[i])
                {
                    len = max(len, 1 + prev[i + 1]);
                }
                cur[p + 1] = len;
            }
            prev = cur;
        }
        return prev[0];
    }
};