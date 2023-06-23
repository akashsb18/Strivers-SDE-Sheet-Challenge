#include <bits/stdc++.h>

int findMinimumCoins(int amount)
{
    vector<int> deno = {1000, 500, 100, 50, 20, 10, 5, 2, 1};

    int i = 0, cnt = 1;
    while (i < 9)
    {
        if (deno[i] > amount)
        {
            i++;
        }
        else
        {
            if (deno[i] == amount)
            {
                return cnt;
            }
            else
            {
                amount -= deno[i];
                cnt++;
            }
        }
    }
    return -1;
}
