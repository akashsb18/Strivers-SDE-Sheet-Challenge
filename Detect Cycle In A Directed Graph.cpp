#include <bits/stdc++.h>

using namespace std;

bool detectCycleInDirectedGraph(int n, vector<pair<int, int>> &edges)
{
    vector<int> indegree(n + 1, 0);

    vector<vector<int>> adj(n + 1);
    for (auto it : edges)
    {
        int u = it.first;
        int v = it.second;
        adj[u].push_back(v);
        indegree[v]++;
    }

    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }

    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        for (auto it : adj[node])
        {
            indegree[it]--;
            if (indegree[it] == 0)
            {
                q.push(it);
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        if (indegree[i] != 0)
        {
            return true;
        }
    }

    return false;
}
