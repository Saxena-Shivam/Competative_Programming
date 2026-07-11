#include <bits/stdc++.h>
using namespace std;
const int N = 1e9 + 7;
int powermod(int a, int b, int mod = N)
{
    long long ans = 1, cur = a % mod;
    while (b > 0)
    {
        if (b & 1)
            ans = (ans * cur) % mod;
        cur = (cur * cur) % mod;
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
        int a, b, c;
        cin >> a >> b >> c;
        cout << powermod(a, powermod(b, c, N - 1)) << endl;
    }
}
