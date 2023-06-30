#include <bits/stdc++.h>
vector<int> mergeKSortedArrays(vector<vector<int>> &kArrays, int k)
{
    vector<int> ans;
    for (int i = 0; i < kArrays.size(); i++)
    {
        vector<int> temp = kArrays[i];
        for (int j = 0; j < temp.size(); j++)
        {
            ans.push_back(temp[j]);
        }
    }
    sort(ans.begin(), ans.end());
    return ans;
}
