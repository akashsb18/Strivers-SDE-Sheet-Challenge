#include <bits/stdc++.h>

vector<int> findMedian(vector<int> &arr, int n)
{

    multiset<int> s;
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        s.insert(arr[i]);

        if ((s.size()) % 2 == 1)
        {
            int middle = s.size() / 2;
            auto it = s.begin();
            std::advance(it, middle);
            int element = *it;
            // return double(element);
            ans.push_back(element);
        }
        else
        {
            int middle1 = s.size() / 2;
            int middle2 = middle1 - 1;
            auto it1 = s.begin();
            std::advance(it1, middle1);
            int element1 = *it1;
            auto it2 = --it1;
            int element2 = *it2;
            double res = (double(element1) + double(element2)) / 2;
            // return ans;
            ans.push_back(res);
        }
    }

    return ans;
}
