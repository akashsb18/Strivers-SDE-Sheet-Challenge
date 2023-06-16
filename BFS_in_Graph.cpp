#include <bits/stdc++.h>
void prepareList(unordered_map<int, set<int>> &adjlist, vector<pair<int, int>> &edges)
{
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;

        adjlist[u].insert(v);
        adjlist[v].insert(u);
    }
}
void bfs(unordered_map<int, set<int>> &adjlist, unordered_map<int, bool> &visited, vector<int> &ans, int node)
{
    queue<int> q;
    q.push(node);
    visited[node] = 1;
    while (!q.empty())
    {
        int frontnode = q.front();
        q.pop();
        ans.push_back(frontnode);
        for (auto it : adjlist[frontnode])
        {
            if (!visited[it])
            {
                visited[it] = 1;
                q.push(it);
            }
        }
    }
    return;
}
vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    // Write your code here
    unordered_map<int, set<int>> adjlist;
    prepareList(adjlist, edges);
    unordered_map<int, bool> visited;
    vector<int> ans;
    for (int i = 0; i < vertex; i++)
    {
        if (!visited[i])
        {
            bfs(adjlist, visited, ans, i);
        }
    }
    return ans;
}