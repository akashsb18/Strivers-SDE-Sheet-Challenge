#include <bits/stdc++.h>
vector<int> getTopView(TreeNode<int> *root)
{
    if (!root)
    {
        return {}; // Return an empty vector if the root is null
    }

    queue<pair<TreeNode<int> *, int>> q;
    map<int, int> mp;
    vector<int> ans;

    q.push({root, 0});

    while (!q.empty())
    {
        TreeNode<int> *node = q.front().first;
        int vert = q.front().second;
        q.pop();

        if (mp.find(vert) == mp.end())
        {
            mp[vert] = node->val;
        }

        if (node->left)
        {
            q.push({node->left, vert - 1});
        }
        if (node->right)
        {
            q.push({node->right, vert + 1});
        }
    }

    for (auto it : mp)
    {
        ans.push_back(it.second);
    }

    return ans;
}
