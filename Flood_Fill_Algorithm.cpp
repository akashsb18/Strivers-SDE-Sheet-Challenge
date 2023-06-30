#include <bits/stdc++.h>

void dfs(int i, int j, vector<vector<int>> &image, int newColor, vector<vector<int>> &vis, int req, int n, int m)
{
    vis[i][j] = 1;
    int delRow[] = {-1, 0, 1, 0};
    int delCol[] = {0, 1, 0, -1};
    for (int k = 0; k < 4; k++)
    {
        int newR = i + delRow[k];
        int newC = j + delCol[k];
        if (newR >= 0 and newR < n and newC >= 0 and newC < m and vis[newR][newC] == 0 and image[newR][newC] == req)
        {
            image[newR][newC] = newColor;
            dfs(newR, newC, image, newColor, vis, req, n, m);
        }
    }
}

vector<vector<int>> floodFill(vector<vector<int>> &image, int x, int y, int newColor)
{
    int n = image.size();
    int m = image[0].size();
    int req = image[x][y];
    image[x][y] = newColor;
    vector<vector<int>> vis(n, vector<int>(m, 0));
    dfs(x, y, image, newColor, vis, req, n, m);
    return image;
}