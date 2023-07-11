
int cutRod(vector<int> &price, int n)
{
    vector<int> prev(n + 1, 0);
    vector<int> curr(n + 1, 0);

    for (int i = 0; i <= n; i++)
    {
        prev[i] = i * price[0];
    }

    for (int ind = 1; ind < n; ind++)
    {
        for (int N = 0; N <= n; N++)
        {
            int notTake = prev[N];
            int take = -1e9;
            int rodLength = ind + 1;
            if (N >= rodLength)
            {
                take = price[ind] + curr[N - rodLength];
            }
            curr[N] = max(notTake, take);
        }
        prev = curr;
    }

    return prev[n];
}
