#include <bits/stdc++.h>
using namespace std;

int main()
{

    vector<vector<int>> edges = {{1, 2, 4},
                                 {1, 3, 3},
                                 {2, 4, 7},
                                 {3, 4, -2}};
    int n = 4, m = 4;

    vector<vector<int>> mat(n, vector<int>(n, -1));

    for (auto it : edges)
    {
        mat[it[0] - 1][it[1] - 1] = it[2];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (mat[i][j] == -1)
            {
                mat[i][j] = INT_MAX;
            }
            if (i == j)
            {
                mat[i][j] = 0;
            }
        }
    }

    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}