#include <bits/stdc++.h>

void setZeros(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>> mat(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            mat[i][j] = matrix[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (mat[i][j] == 0)
            {
                for (int k = 0; k < m; k++)
                {
                    matrix[i][k] = 0;
                }
                for (int k = 0; k < n; k++)
                {
                    matrix[k][j] = 0;
                }
            }
        }
    }
}