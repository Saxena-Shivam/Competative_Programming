#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
vector<vector<int>> cc;
vector<int> temp_cc;
vector<bool> visited(N, false);
vector<int> graph[N];
void dfs(int vertex)
{
    visited[vertex] = true;
    temp_cc.push_back(vertex);
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
        temp_cc.clear();
        if (visited[i])
            continue;
        dfs(i);
        cc.push_back(temp_cc);
    }
    cout << cc.size() << endl;
    for (int i = 0; i < cc.size(); i++)
    {
        for (int j = 0; j < (int)cc[i].size(); j++)
        {
            cout << cc[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}