#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef tree<long long, null_type, greater_equal<long long>, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef long long ll;
#define fr(i, n) for (int i = 0; i < n; i++)
#define fr1(i, n) for (int i = 1; i < n; i++)
#define endl "\n"
#define vi vector<int>
#define vpii vector<pair<int, int>>
#define vpll vector<pair<ll, ll>>
#define vll vector<ll>
#define ump unordered_map<int, int>
#define mpii map<int, int>
#define mpll map<ll, ll>
#define si set<int>
#define spii set<pair<int, int>>
#define pi pair<int, int>
#define pb push_back
#define sz(x) (int)(x).size()
#define all(x) x.begin(), x.end()
#define vecin(name, len)   \
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
// -------------------- DEBUGGING --------------------
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
#define debug(x)         \
    cerr << #x << " = "; \
    _print(x);           \
    cerr << endl;
#else
#define debug(x)
#endif

void _print(int x) { cerr << x; }
void _print(long x) { cerr << x; }
void _print(long long x) { cerr << x; }
void _print(unsigned x) { cerr << x; }
void _print(unsigned long x) { cerr << x; }
void _print(unsigned long long x) { cerr << x; }
void _print(float x) { cerr << x; }
void _print(double x) { cerr << x; }
void _print(long double x) { cerr << x; }
void _print(char x) { cerr << '\'' << x << '\''; }
void _print(const char *x) { cerr << '\"' << x << '\"'; }
void _print(const string &x) { cerr << '\"' << x << '\"'; }
void _print(bool x) { cerr << (x ? "true" : "false"); }

template <typename T, typename V>
void _print(const pair<T, V> &x)
{
    cerr << '{';
    _print(x.first);
    cerr << ", ";
    _print(x.second);
    cerr << '}';
}
template <typename T>
void _print(const vector<T> &v)
{
    cerr << '[';
    for (size_t i = 0; i < v.size(); ++i)
    {
        _print(v[i]);
        if (i != v.size() - 1)
            cerr << ", ";
    }
    cerr << ']';
}
template <typename T>
void _print(const set<T> &v)
{
    cerr << '{';
    for (auto i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << '}';
}
template <typename T>
void _print(const multiset<T> &v)
{
    cerr << '{';
    for (auto i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << '}';
}
template <typename T>
void _print(const unordered_set<T> &v)
{
    cerr << '{';
    for (auto i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << '}';
}
template <typename T, typename V>
void _print(const map<T, V> &v)
{
    cerr << '{';
    for (auto i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << '}';
}
template <typename T, typename V>
void _print(const multimap<T, V> &v)
{
    cerr << '{';
    for (auto i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << '}';
}
template <typename T, typename V>
void _print(const unordered_map<T, V> &v)
{
    cerr << '{';
    for (auto i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << '}';
}

// -------------------- OUTPUT --------------------

void print(int x) { cout << x << "\n"; }
void print(long x) { cout << x << "\n"; }
void print(long long x) { cout << x << "\n"; }
void print(unsigned x) { cout << x << "\n"; }
void print(unsigned long x) { cout << x << "\n"; }
void print(unsigned long long x) { cout << x << "\n"; }
void print(float x) { cout << x << "\n"; }
void print(double x) { cout << x << "\n"; }
void print(long double x) { cout << x << "\n"; }
void print(char x) { cout << x << "\n"; }
void print(const char *x) { cout << x << "\n"; }
void print(const string &x) { cout << x << "\n"; }
void print(bool x) { cout << (x ? "YES" : "NO") << "\n"; }

void print_(int x) { cout << x << " "; }
void print_(long x) { cout << x << " "; }
void print_(long long x) { cout << x << " "; }
void print_(unsigned x) { cout << x << " "; }
void print_(unsigned long x) { cout << x << " "; }
void print_(unsigned long long x) { cout << x << " "; }
void print_(float x) { cout << x << " "; }
void print_(double x) { cout << x << " "; }
void print_(long double x) { cout << x << " "; }
void print_(char x) { cout << x << " "; }
void print_(const char *x) { cout << x << " "; }
void print_(const string &x) { cout << x << " "; }
void print_(bool x) { cout << x << " "; }

template <typename T, typename V>
void print(const pair<T, V> &x)
{
    print_(x.first);
    cout << " ";
    print_(x.second);
    cout << '\n';
}
template <typename T>
void print(const vector<T> &v)
{
    for (auto i : v)
        print_(i);
    cout << '\n';
}
template <typename T>
void print(const set<T> &v)
{
    for (auto i : v)
        print_(i);
    cout << '\n';
}
template <typename T>
void print(const multiset<T> &v)
{
    for (auto i : v)
        print_(i);
    cout << '\n';
}
template <typename T>
void print(const unordered_set<T> &v)
{
    for (auto i : v)
        print_(i);
    cout << '\n';
}
template <typename T, typename V>
void print(const map<T, V> &v)
{
    for (auto i : v)
        print_(i);
    cout << '\n';
}
template <typename T, typename V>
void print(const multimap<T, V> &v)
{
    for (auto i : v)
        print_(i);
    cout << '\n';
}
template <typename T, typename V>
void print(const unordered_map<T, V> &v)
{
    for (auto i : v)
        print_(i);
    cout << '\n';
}
//----max function----
template <typename T1, typename T2>
auto max(T1 a, T2 b) -> decltype(a + b)
{
    return (a > b) ? a : b;
}
template <typename T1, typename T2>
auto min(T1 a, T2 b) -> decltype(a + b)
{
    return (a < b) ? a : b;
}
class DisjointSet
{
    vector<int> rank, parent, size;

public:
    DisjointSet(int n)
    {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node)
    {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v)
    {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v)
            return;
        if (rank[ulp_u] < rank[ulp_v])
        {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u])
        {
            parent[ulp_v] = ulp_u;
        }
        else
        {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v)
    {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v)
            return;
        if (size[ulp_u] < size[ulp_v])
        {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else
        {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};
// -------------------- CONSTANTS --------------------
const int modulo = 1e9 + 7;
const int N = 2e5 + 5;
const long long INF = 1e18;
const int mod = 998244353;
vector<ll> fact, invFact;
// Useful Functions

ll add(ll a, ll b) { return (a + b) % mod; }

ll sub(ll a, ll b) { return (a - b + mod) % mod; }

ll mul(ll a, ll b) { return (a * b) % mod; }

ll power(ll x, ll y)
{
    ll r = 1;
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

ll inv(ll a) { return power(a, mod - 2); }

ll nCrmod(int n, int r)
{
    if (r < 0 || r > n)
        return 0;
    return mul(fact[n], mul(invFact[r], invFact[n - r]));
}

void precomputefac(int n)
{
    fact.assign(n + 1, 0);
    invFact.assign(n + 1, 0);
    fact[0] = 1;
    for (int i = 1; i <= n; i++)
        fact[i] = mul(fact[i - 1], i);
    invFact[n] = inv(fact[n]);
    for (int i = n - 1; i >= 0; i--)
        invFact[i] = mul(invFact[i + 1], i + 1);
}

ll nCr(ll n, ll r)
{
    if (r < 0 || r > n)
        return 0;
    if (r > n - r)
        r = n - r;

    ll res = 1;
    for (ll i = 1; i <= r; i++)
    {
        res = res * (n - r + i) / i;
    }
    return res;
}

ll mex(vi &a)
{
    set<int> s;
    for (auto x : a)
        s.insert(x);
    ll mex = 0;
    for (auto x : s)
    {
        if (x == mex)
            mex++;
        else
            break;
    }
    return mex;
}

ll xorUpto(ll n)
{
    if (n % 4 == 0)
        return n;
    if (n % 4 == 1)
        return 1;
    if (n % 4 == 2)
        return n + 1;
    return 0;
}

ll bin_exp(ll a, ll b)
{
    ll ans = 1;
    while (b > 0)
    {
        if (b % 2)
            ans = (ans * a);
        a = (a * a);
        b >>= 1;
    }
    return ans;
}

vector<int> sieve(int n)
{
    vector<int> isPrime(1e7 + 1, 1);
    isPrime[0] = isPrime[1] = 0;
    for (int i = 2; i * i <= n; i++)
        if (isPrime[i])
            for (int j = i * i; j <= n; j += i)
                isPrime[j] = 0;
    return isPrime;
}

vector<ll> all_divisors(int num)
{
    vector<ll> ans;
    ans.push_back(1);
    for (int i = 2; i * i <= num; i++)
    {
        if (num % i == 0)
        {
            ans.push_back(i);
            if (num / i != i)
                ans.push_back(num / i);
        }
    }
    return ans;
}

map<long long, int> primeFactorize(long long n)
{
    map<long long, int> factors;
    while (n % 2 == 0)
    {
        factors[2]++;
        n /= 2;
    }
    for (long long i = 3; i * i <= n; i += 2)
    {
        while (n % i == 0)
        {
            factors[i]++;
            n /= i;
        }
    }
    if (n > 1)
    {
        factors[n]++;
    }
    return factors;
}

int tc = 1;
namespace work
{
    ll solve()
    {
    }
}
template <typename F>
void run(F &&func)
{
    using ret = decltype(func());

    if constexpr (std::is_void_v<ret>)
    {
        func();
    }
    else
    {
        cout << func() << endl;
    }
}
int main()
{
    speed;
    auto begin = std::chrono::high_resolution_clock::now();
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif

    using ret = decltype(work ::solve());
    if (tc)
    {
        int T;
        cin >> T;
        while (T--)
        {
            run(work::solve);
        }
    }
    else
    {
        run(work::solve);
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n";
    return 0;
}
