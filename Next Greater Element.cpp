#include <bits/stdc++.h>

vector<int> nextGreater(vector<int> &nums, int n)
{

    stack<int> st;
    vector<int> ans(n, -1);

    for (int i = 0; i < n; i++)
    {

        while (!st.empty() and nums[st.top()] < nums[i])
        {
            ans[st.top()] = nums[i];
            st.pop();
        }
        if (i < n)
        {
            st.push(i);
        }
    }

    return ans;
}