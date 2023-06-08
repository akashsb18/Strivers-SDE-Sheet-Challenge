#include <bits/stdc++.h>

pair<int, int> missingAndRepeating(vector<int> &arr, int n)
{

    int repeat = 0, miss = 0;
    unordered_map<int, int> mp;
    for (auto it : arr)
    {
        mp[it]++;
    }
    for (auto it : mp)
    {
        if (it.second > 1)
        {
            repeat = it.first;
            break;
        }
    }
    sort(arr.begin(), arr.end());
    unique(arr.begin(), arr.end());
    for (int i = 1; i <= n; i++)
    {
        if (i != arr[i - 1])
        {
            miss = i;
            break;
        }
    }

    return {miss, repeat};
}
