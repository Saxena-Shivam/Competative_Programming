#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(i, n) for (int i = 0; i < n; i++)
#define fr1(i, n) for (int i = 1; i < n; i++)
#define endl "\n"
#define vi vector<int>
#define vpii vector<pair<int, int>>
#define mpii map<int, int>
#define si set<int>
#define spii set<pair<int, int>>
#define pi pair<int, int>
#define pb push_back
#define all(x) x.begin(), x.end()
#define veclin(name, len)  \
    vector<int> name(len); \
    for (auto &_ : name)   \
        cin >> _;
#define veclin(name, len) \
    vector<ll> name(len); \
    for (auto &_ : name)  \
        cin >> _;
#define vecout(v)         \
    for (auto _ : v)      \
        cout << _ << " "; \
    cout << endl;
#define speed                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

// Constants
const int mod = 1e9 + 7;

// Useful Functions
int bin_exp(int a, int b)
{
    int ans = 1;
    while (b > 0)
    {
        if (b % 2)
            ans = (ans * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return ans;
}
vi sieve(int n)
{
    vi isPrime(n + 1, 1);
    isPrime[0] = isPrime[1] = 0;
    for (int i = 2; i * i <= n; i++)
        if (isPrime[i])
            for (int j = i * i; j <= n; j += i)
                isPrime[j] = 0;
    return isPrime;
}
int nCr(int n, int r)
{
    if (r > n - r)
        r = n - r;
    long res = 1;

    for (int i = 0; i < r; i++)
    {
        res *= (n - i);
        res /= (i + 1);
    }

    return (int)res;
}

long add(long a, long b) { return (a + b) % mod; }
long sub(long a, long b) { return (a - b + mod) % mod; }
long mul(long a, long b) { return (a * b) % mod; }
long power(long x, long y)
{
    long r = 1;
    x %= mod;
    while (y)
    {
        if (y & 1)
            r = mul(r, x);
        x = mul(x, x);
        y >>= 1;
    }
    return r;
}
long inv(long a) { return power(a, mod - 2); }
long divmod(long a, long b) { return mul(a, inv(b)); }
void solve()
{
    ll n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int a = 0, b = 0;
    for (auto c : s)
    {
        if (c == 'a')
            a++;
        else
            b++;
    }
    int ct = 0, maxi = 0;
    for (auto c : s)
    {
        if (c == 'a')
            ct++;
        else
        {
            maxi = max(ct, maxi);
            ct = 0;
        }
    }
    if (ct)
}
int main()
{
    speed;
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}