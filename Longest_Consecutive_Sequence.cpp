#include <bits/stdc++.h>

int lengthOfLongestConsecutiveSequence(vector<int> &nums, int n)
{
    unordered_set<int> uniqueNumbers(nums.begin(), nums.end());
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (uniqueNumbers.find(nums[i] - 1) == uniqueNumbers.end())
        {
            int cnt = 0;
            int num = nums[i];

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
