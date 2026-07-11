#include <iostream>
#include <vector>
using namespace std;

int main()
{
    // Your code here
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++)
    {
        int v1, v2;
        cin >> v1 >> v2;
        adj[v1].push_back(v2);
        adj[v2].push_back(v1);
    }
    for (int i = 1; i <= n; i++)
    {
        cout << i << " -> ";
        for (int j = 0; j < (int)adj[i].size(); j++)
        {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}