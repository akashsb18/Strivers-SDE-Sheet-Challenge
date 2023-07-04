#include <bits/stdc++.h>

vector<vector<int>> ans;

void dfs(int i, vector<int> &vis, vector<int> adj[], vector<int> &temp)
{
    vis[i] = 1;
    temp.push_back(i);
    for (auto it : adj[i])
    {
        if (vis[it] == 0)
        {
            dfs(it, vis, adj, temp);
        }
    }
}

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{

    vector<int> adj[V];
    for (auto it : edges)
    {
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
    }
    vector<int> vis(V, 0);
    for (int i = 0; i < V; i++)
    {
        vector<int> temp;
        if (vis[i] == 0)
        {
            dfs(i, vis, adj, temp);
            ans.push_back(temp);
        }
    }
    return ans;
}