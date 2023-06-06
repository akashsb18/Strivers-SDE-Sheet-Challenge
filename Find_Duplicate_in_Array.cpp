#include <bits/stdc++.h>

int findDuplicate(vector<int> &arr, int n)
{
    unordered_map<int, int> mp;
    for (auto it : arr)
    {
        mp[it]++;
    }
    for (auto it : mp)
    {
        if (it.second > 1)
        {
            return it.first;
        }
    }
    return -1;
}
