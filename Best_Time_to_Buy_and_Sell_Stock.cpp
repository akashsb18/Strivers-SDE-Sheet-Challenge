#include <bits/stdc++.h>
int maximumProfit(vector<int> &v)
{
    int mini = v[0], profit = INT_MIN;
    for (int i = 1; i < v.size(); i++)
    {
        int cost = v[i] - mini;
        profit = max(profit, cost);
        mini = min(mini, v[i]);
    }
    if (profit < 0)
    {
        return 0;
    }
    return profit;
}