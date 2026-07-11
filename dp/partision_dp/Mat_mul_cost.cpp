#include <bits\stdc++.h>
using namespace std;
class Solution
{
public:
    int matrixMultiplication(vector<int> &arr)
    {
        // code here
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int i = n - 1; i >= 1; i--)
        {
            for (int j = i + 1; j < n; j++)
            {
                int mini = 1e9;
                for (int k = i; k < j; k++)
                {
                    int step = arr[i - 1] * arr[k] * arr[j] + dp[i][k] + dp[k + 1][j];
                    mini = min(mini, step);
                }
                dp[i][j] = mini;
            }
        }
        return dp[1][n - 1];
    }

private:
    int solve(vector<int> &arr, int i, int j, vector<vector<int>> &dp)
    {
        if (i == j)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        int mini = 1e9;
        for (int k = i; k < j; k++)
        {
            int step = arr[i - 1] * arr[k] * arr[j] + solve(arr, i, k, dp) + solve(arr, k + 1, j, dp);
            mini = min(mini, step);
        }
        return dp[i][j] = mini;
    }
};