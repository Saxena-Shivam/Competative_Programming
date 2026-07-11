#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
vector<int> graph[N];
vector<bool> visited(N, false);
void dfs(int vertex)
{
    // take action on vertex after entering the vertex
    cout << "vertex " << vertex << endl;
    visited[vertex] = true;
    for (int child : graph[vertex])
    {
        cout << " parents " << vertex << " child  " << child << endl;
        // take action on the child before entering the child node
        if (visited[child])
            continue;
        dfs(child);
        // take action on the child after existing the child node
    }
    // take action the vertex before existing vertex node
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
    dfs(3);
    return 0;
}
// Time complexity: O(N + M), where N is the number of vertices and M is the number of edges.
// Space complexity: O(N + M), where N is the number of vertices and M is the number of edges.
// input
// 6 9
// 1 3
// 1 5
// 3 5
// 3 4
// 3 6
// 3 2
// 2 6
// 4 6
// 5 6
