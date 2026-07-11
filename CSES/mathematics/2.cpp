#include <bits/stdc++.h>
using namespace std;
const int N = 1e9 + 7;
int powermod(int a, int b)
{
    int res = 1, ans = 1;
    while (b > 0)
    {
        if (b & 1)
        {
            ans = (ans * 1LL * a) % N;
        }
        a = (a * 1LL * a) % N;
        b >>= 1;
    }
    return ans;
}
int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        int a, b;
        cin >> a >> b;
        cout << powermod(a, b) << endl;
    }
}