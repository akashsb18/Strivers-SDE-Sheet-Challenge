
// Memoization
class Solution
{
public:
    int f(int i, int j, int m, int n, vector<vector<int>> &dp)
    {

        if (i == m - 1 || j == n - 1)
        {
            return 1;
        }

        if (i >= m || j >= n)
        {
            return 0;
        }

        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }

        int right = f(i, j + 1, m, n, dp);
        int down = f(i + 1, j, m, n, dp);

        return dp[i][j] = right + down;
    }

    int uniquePaths(int m, int n)
    {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
        return f(0, 0, m, n, dp);
    }
};
// Tabulation
vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

for (int i = m - 1; i >= 0; i--)
{
    for (int j = n - 1; j >= 0; j--)
    {
        if (i == m - 1 or j == n - 1)
        {
            dp[i][j] = 1;
        }
        else
        {
            int right = dp[i][j + 1];
            int down = dp[i + 1][j];

            dp[i][j] = right + down;
        }
    }
}

return dp[0][0];