#include <bits/stdc++.h>
using namespace std;
int kthElement(vector<int> &a, vector<int> &b, int k)
{
    // code here
    int i = 0, j = 0;
    int ans = -1;
    while (k > 0)
    {
        if (a[i] < b[j])
        {
            ans = a[i];
            i++;
        }
        else if (a[i] == b[j])
        {
            if (i < a.size())
            {
                ans = a[i];
                i++;
            }
            else
            {
                ans = b[j];
                j++;
            }
        }
        else
        {
            ans = b[j];
            j++;
        }
        k--;
    }
    return ans;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        vector<int> a = {1, 2, 3};
        vector<int> b = {2, 3, 3};
        int k;
        cin >> k;
        cout << kthElement(a, b, k);
    }
    return 0;
}