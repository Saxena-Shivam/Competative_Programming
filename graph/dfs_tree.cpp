#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
vector<int> graph[N];
void dfs(int vertex, int par = 0)
{
    for (int child : graph[vertex])
    {
        if (child == par)
            continue;
        dfs(child, vertex);
    }
}
int main()
{
    // Your code here
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    dfs(1);
    return 0;
}