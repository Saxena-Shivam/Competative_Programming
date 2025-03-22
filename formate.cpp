#include <bits/stdc++.h>
using namespace std;
// Typedefs for commonly used types
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vp;
typedef vector<vector<int>> vvi;
typedef vector<vector<ll>> vvll;
typedef priority_queue<int, vector<int>, greater<int>> min_heap;
typedef priority_queue<int> max_heap;
auto cmp = [](pair<int, int> &pair1, pair<int, int> &pair2)
{
    if (pair1.first != pair2.first)
        return pair1.first > pair2.first;
    return pair1.second > pair2.second;
};
typedef priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pair_heap;
// Constants
const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll LINF = 1e18;
const int ix = INT_MAX;
const int in = INT_MIN;
const ll lx = LONG_MAX;
const ll ln = LONG_MIN;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

// Macros
#define int int32_t
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define pb push_back
#define mp make_pair
#define all(v) v.begin(), v.end()
#define SORT(v) sort(all(v))
#define RSORT(v) sort(v.rbegin(), v.rend())
#define UNIQUE(v) v.erase(unique(all(v)), v.end())
#define SUM(v) accumulate(all(v), 0LL)
#define MAXI(a) (*max_element(all(a)))
#define MINI(a) (*min_element(all(a)))
#define SZ(v) ((int)v.size())
#define REVERSE(v) reverse(all(v))
#define LOWER_BOUND(v, x) (lower_bound(all(v), x) - v.begin())
#define UPPER_BOUND(v, x) (upper_bound(all(v), x) - v.begin())

// String Macros
#define REVERSE_STR(s) reverse(all(s))
#define SORT_STR(s) sort(all(s))
#define UNIQUE_STR(s) s.erase(unique(all(s)), s.end())

// Input/Output macros
#define read(a)       \
    for (auto &i : a) \
    cin >> i
#define print(a)          \
    for (auto &i : a)     \
        cout << i << " "; \
    cout << "\n"
#define read2(a, n, m)                \
    for (int i = 0; i < (n); ++i)     \
        for (int j = 0; j < (m); ++j) \
    cin >> (a)[i][j]
#define print2(a, n, m)               \
    for (int i = 0; i < (n); ++i)     \
    {                                 \
        for (int j = 0; j < (m); ++j) \
            cout << (a)[i][j] << " "; \
        cout << endl;                 \
    }

// Loop macros
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define repd(i, a, b) for (int i = (a); i >= (b); --i)
#define fl(i, n) rep(i, 0, n)
#define rfl(i, n) repd(i, n - 1, 0)

// Comparators
#define cmpv [](int a, int b) { return a < b; }
#define cmpp [](pii &pair1, pii &pair2) { if (pair1.second != pair2.second) return pair1.second < pair2.second; return pair1.first < pair2.first; }

// Modular arithmetic
inline int add(int a, int b, int mod = MOD) { return (a + b) % mod; }
inline int sub(int a, int b, int mod = MOD) { return (a - b + mod) % mod; }
inline int mul(int a, int b, int mod = MOD) { return (int)((1LL * a * b) % mod); }
inline int binpow(int a, int b, int mod = MOD)
{
    int res = 1;
    while (b)
    {
        if (b & 1)
            res = mul(res, a, mod);
        a = mul(a, a, mod);
        b >>= 1;
    }
    return res;
}

int32_t main()
{
    fast;
    int t;
    cin >> t;
    while (t--)
    {
    }
    return 0;
}
