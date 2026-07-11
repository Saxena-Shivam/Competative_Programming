#include <bits\stdc++.h>
using namespace std;
vector<int> printingLongestIncreasingSubsequence(vector<int> arr, int n)
{
    vector<int> dp(n, 1), idx(n);
    for (int i = 0; i < n; i++)
        idx[i] = i;
    int maxi = 1, lastIndex = 0;
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[j] < arr[i] && dp[j] + 1 > dp[i])
            {
                dp[i] = dp[j] + 1;
                idx[i] = j;
            }
        }
        if (dp[i] > maxi)
        {
            maxi = dp[i];
            lastIndex = i;
        }
    }
    vector<int> ans;
    while (idx[lastIndex] != lastIndex)
    {
        ans.push_back(arr[lastIndex]);
        lastIndex = idx[lastIndex];
    }
    ans.push_back(arr[lastIndex]);
    reverse(ans.begin(), ans.end());
    return ans;
}