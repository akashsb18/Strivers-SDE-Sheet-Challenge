#include <bits/stdc++.h>

int f(int ind, int W, vector<int> &val, vector<int> &wht, vector<vector<int>> &dp)
{

    if (ind == 0)
    {
        if (W >= wht[0])
        {
            return val[0];
        }
        else
        {
            return 0;
        }
    }

    if (dp[ind][W] != -1)
    {
        return dp[ind][W];
    }

    int notPick = 0 + f(ind - 1, W, val, wht, dp);
    int pick = -1e9;
    if (W >= wht[ind])
    {
        pick = val[ind] + f(ind - 1, W - wht[ind], val, wht, dp);
    }

    return dp[ind][W] = max(pick, notPick);
}

int maxProfit(vector<int> &values, vector<int> &weights, int n, int w)
{
    vector<vector<int>> dp(n + 1, vector<int>(w + 1, -1));
    return f(n - 1, w, values, weights, dp);
}