#include <bits/stdc++.h>
int bellmonFord(int n, int m, int src, int dest, vector<vector<int>> &edges)
{

    vector<int> dist(n + 1, 1e9);

    dist[src] = 0;

    for (int i = 1; i <= n - 1; i++)
    {
        for (auto it : edges)
        {
            int u = it[0], v = it[1], wt = it[2];
            if (dist[u] != 1e9 and wt + dist[u] < dist[v])
            {
                dist[v] = wt + dist[u];
            }
        }
    }

    return dist[dest];
}