#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> subsetsvectors;
void subsetvector(vector<int> &s, int k)
{
    int n = s.size();
    for (int i = 0; i < (1 << n); i++)
    {
        vector<int> temp;
        for (int j = 0; j < n; j++)
        {
            if (i & (1 << j))
            {
                temp.push_back(s[j]);
            }
        }
        if ((int)temp.size() == k)
            subsetsvectors.push_back(temp);
    }
}

vector<string> subsets;
void subset(string &s)
{
    int n = s.size();
    for (int i = 0; i < (1 << n); i++)
    {
        string temp = "";
        for (int j = 0; j < n; j++)
        {
            if (i & (1 << j))
            {
                temp += s[j];
            }
        }
        subsets.push_back(temp);
    }
}
vector<string> substrings;
void substring(string &s)
{
    int n = s.size();
    for (int i = 0; i < n; i++)
    {
        string substring = "";
        for (int j = i; j < n; j++)
        {
            substring += s[j];
            substrings.push_back(substring);
        }
    }
}

vector<vector<int>> subarrays;
void generateSubarrays(vector<int> &s)
{
    int n = s.size();
    for (int i = 0; i < n; i++)
    {
        vector<int> subarray;
        for (int j = i; j < n; j++)
        {
            subarray.push_back(s[j]);
            subarrays.push_back(subarray);
        }
    }
}
int main()
{
    string s = "abc";
    vector<int> v = {1, 2, 5, 7, 10};
    subsetvector(v, 3);
    for (auto i : subsetsvectors)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}