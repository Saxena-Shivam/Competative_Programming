#include <bits/stdc++.h>
using namespace std;

int main()
{
    // Your code here
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1, vector<int>(n + 1, 0));
    for (int i = 0; i < m; i++)
    {
        int v1, v2;
        cin >> v1 >> v2;
        adj[v1][v2] = 1;
        adj[v2][v1] = 1;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }
    // is i,j connected?
    int i, j;
    cin >> i >> j;
    cout << (adj[i][j] == 1 ? "Connected" : "Not connected") << endl;

    return 0;
}