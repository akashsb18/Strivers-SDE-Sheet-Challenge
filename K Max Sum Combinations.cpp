#include <bits/stdc++.h>
vector<int> kMaxSumCombination(vector<int> &nums1, vector<int> &nums2, int n, int k)
{
    priority_queue<pair<int, pair<int, int>>> pq;
    sort(nums1.rbegin(), nums1.rend());
    sort(nums2.rbegin(), nums2.rend());
    pq.push({nums1[0] + nums2[0], {0, 0}});

    set<pair<int, int>> visited;
    visited.insert({0, 0});
    vector<int> ans;
    for (int ind = 0; ind < k && !pq.empty(); ind++)
    {

        int i = pq.top().second.first;
        int j = pq.top().second.second;

        ans.push_back(pq.top().first);
        pq.pop();

        if (i + 1 < n and !visited.count({i + 1, j}))
        {
            pq.push({nums1[i + 1] + nums2[j], {i + 1, j}});
            visited.insert({i + 1, j});
        }
        if (j + 1 < n and !visited.count({i, j + 1}))
        {
            pq.push({nums1[i] + nums2[j + 1], {i, j + 1}});
            visited.insert({i, j + 1});
        }
    }

    return ans;
}