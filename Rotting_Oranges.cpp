#include <bits/stdc++.h>
int minTimeToRot(vector<vector<int>> &grid, int n, int m)
{
    int c1 = 0;
    vector<vector<int>> vis(n, vector<int>(m, 0));
    // {{x,y},z}
    queue<pair<pair<int, int>, int>> q;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 2)
            {
                q.push({{i, j}, 0});
                vis[i][j] = 2;
            }
            if (grid[i][j] == 1)
            {
                c1++;
            }
        }
    }
    int ct = 0, c2 = 0;
    int delRow[] = {-1, 0, 1, 0};
    int delCol[] = {0, 1, 0, -1};
    while (!q.empty())
    {
        int r = q.front().first.first;
        int c = q.front().first.second;
        ct = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int newR = r + delRow[i];
            int newC = c + delCol[i];
            if (newR >= 0 and newR < n and newC >= 0 and newC < m and vis[newR][newC] != 2 and grid[newR][newC] == 1)
            {
                q.push({{newR, newC}, ct + 1});
                vis[newR][newC] = 2;
                c2++;
            }
        }
    }

    if (c1 - c2 != 0)
    {
        return -1;
    }
    return ct;
}