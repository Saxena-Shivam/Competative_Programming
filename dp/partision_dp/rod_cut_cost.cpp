#include <bits\stdc++.h>
using namespace std;
class Solution
{
private:
    int solve(vector<int> &arr, int i, int j, vector<vector<int>> &dp)
    {
        if (i > j)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        int mini = INT_MAX;
        for (int k = i; k <= j; k++)
        {
            int step = arr[j + 1] - arr[i - 1] + solve(arr, i, k - 1, dp) + solve(arr, k + 1, j, dp);
            mini = min(mini, step);
        }
        return dp[i][j] = mini;
    }

public:
    int minCost(int n, vector<int> &cuts)
    {
        int m = cuts.size();
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        vector<vector<int>> dp(m + 1, vector<int>(m + 1, -1));
        return solve(cuts, 1, m, dp);
    }
};