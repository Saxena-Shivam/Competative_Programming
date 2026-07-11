#include <bits/stdc++.h>
using namespace std;

int main()
{
    // Your code here
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> adj(n + 1);
    for (int i = 0; i < m; i++)
    {
        int v1, v2, w;
        cin >> v1 >> v2 >> w;
        adj[v1].push_back({v2, w});
        adj[v2].push_back({v1, w});
    }
    for (int i = 1; i <= n; i++)
    {
        cout << i << " -> ";
        for (int j = 0; j < (int)adj[i].size(); j++)
        {
            cout << adj[i][j].first << " (" << adj[i][j].second << ") ";
        }
        cout << endl;
    }
    // are i j connected?
    int i, j;
    cin >> i >> j;
    bool connected = false;
    for (int k = 0; k < (int)adj[i].size(); k++)
    {
        if (adj[i][k].first == j)
        {
            connected = true;
            break;
        }
    }
    cout << (connected ? "Connected" : "Not connected") << endl;

    return 0;
}