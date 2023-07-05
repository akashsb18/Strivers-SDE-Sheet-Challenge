#include <bits/stdc++.h>

bool isValid(int i, int j, int **arr, int n, int m)
{
    if (i >= 0 and i < n and j >= 0 and j < m and arr[i][j] == 1)
    {
        return true;
    }
    return false;
}

void dfs(int i, int j, int **arr, int n, int m)
{
    arr[i][j] = 0;
    int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

    for (int k = 0; k < 8; k++)
    {
        int newR = i + dx[k];
        int newC = j + dy[k];
        if (isValid(newR, newC, arr, n, m))
        {
            dfs(newR, newC, arr, n, m);
        }
    }
}

int getTotalIslands(int **arr, int n, int m)
{

    int c = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == 1)
            {
                dfs(i, j, arr, n, m);
                c++;
            }
        }
    }
    return c;
}
