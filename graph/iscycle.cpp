#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
vector<bool> visited(N, false);
vector<int> graph[N];
bool iscyce(int vertex, int parent)
{
    visited[vertex] = true;
    bool isloop = false;
    for (int child : graph[vertex])
    {
        if (visited[child] && child != parent)
            return true;
        if (visited[child])
            continue;
        isloop |= iscyce(child, vertex);
    }
    return isloop;
}
void dfs(int vertex)
{
    visited[vertex] = true;
    for (int child : graph[vertex])
    {
        if (visited[child])
            continue;
        dfs(child);
    }
}
int main()
{
    // Your code here
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int v1, v2;
        cin >> v1 >> v2;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }
    for (int i = 1; i <= n; i++)
    {
        if (visited[i])
            continue;
        if (iscyce(i, -1))
        {
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
    return 0;
}