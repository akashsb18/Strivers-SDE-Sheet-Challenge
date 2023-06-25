#include <bits/stdc++.h>

bool solve(int n, int tar, vector<int> &a, vector<vector<int>> &dp)
{

    if (tar == 0)
        return 1;

    if (n == 0)
    {

        if (tar == a[0])
            return 1;

        return 0;
    }

    if (dp[n][tar] != -1)
        return dp[n][tar];

    bool excl = 0;

    // exclude

    excl = solve(n - 1, tar, a, dp);

    // include

    bool inclu = 0;

    if (a[n] <= tar)

        inclu = solve(n - 1, tar - a[n], a, dp);

    return dp[n][tar] = (inclu || excl);
}

bool tab(int n, int tar, vector<int> &a)
{

    vector<vector<bool>> dp(n, vector<bool>(tar + 1, 0));

    for (int i = 0; i < n; i++)

        dp[i][0] = 1;

    dp[0][a[0]] = 1;

    for (int i = 1; i < n; i++)
    {

        for (int j = 1; j <= tar; j++)
        {

            bool excl = dp[i - 1][j];

            bool inclu = 0;

            if (j - a[i] >= 0)

                inclu = dp[i - 1][j - a[i]];

            dp[i][j] = (inclu | excl);
        }
    }

    if (dp[n - 1][tar])
        return 1;

    return 0;
}

bool SO(int n, int tar, vector<int> &a)
{

    vector<bool> prev(tar + 1, 0);

    prev[0] = 1;

    prev[a[0]] = 1;

    for (int i = 1; i < n; i++)
    {

        vector<bool> curr(tar + 1, 0);

        curr[0] = 1;

        for (int j = 1; j <= tar; j++)
        {

            bool excl = prev[j];

            bool inclu = 0;

            if (j - a[i] >= 0)

                inclu = prev[j - a[i]];

            curr[j] = (inclu | excl);
        }

        prev = curr;
    }

    if (prev[tar])
        return 1;

    return 0;
}

bool subsetSumToK(int n, int k, vector<int> &arr)
{

    //    vector<vector<int>>dp(n,vector<int>(k+1,-1));

    //    return solve(n-1,k,arr,dp);

    //    return tab(n,k,arr);

    return SO(n, k, arr);
}