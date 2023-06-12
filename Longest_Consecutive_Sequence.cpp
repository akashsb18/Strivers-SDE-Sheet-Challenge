#include <bits/stdc++.h>

int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n)
{
    unordered_set<int> uniqueNumbers(arr.begin(), arr.end());
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (uniqueNumbers.find(arr[i] - 1) == uniqueNumbers.end())
        {
            int cnt = 0;
            int num = arr[i];

            while (uniqueNumbers.find(num) != uniqueNumbers.end())
            {
                cnt++;
                num++;
            }

            ans = max(ans, cnt);
        }
    }

    return ans;
}
