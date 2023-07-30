#include <bits/stdc++.h>
    int f(int ind, int prev_ind, vector<int> &v, vector<vector<int>> &dp)
    {

        if (ind == v.size())
        {
            return 0;
        }

        if (dp[ind][prev_ind + 1] != -1)
        {
            return dp[ind][prev_ind + 1];
        }

        int notTake = 0 + f(ind + 1, prev_ind, v, dp);
        int take = -1e9;
        if (prev_ind == -1 or v[ind] > v[prev_ind])
        {
            take = v[ind] + f(ind + 1, ind, v, dp);
        }

        return dp[ind][prev_ind + 1] = max(notTake, take);
    }
int maxIncreasingDumbbellsSum(vector<int> &rack, int n)
{
    vector<vector<int>> dp(n+1,vector<int> (n+1,-1));
	return f(0,-1,rack,dp);
}