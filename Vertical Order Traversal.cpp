#include <bits/stdc++.h>
/************************************************************

Following is the Binary Tree node class

template <typename T = int>
class TreeNode
{
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T val)
    {
        this->data = val;
        left = NULL;
        right = NULL;
    }

    ~TreeNode()
    {
        if (left != NULL)
        {
            delete left;
        }
        if (right != NULL)
        {
            delete right;
        }
    }
};

************************************************************/

vector<int> verticalOrderTraversal(TreeNode<int> *root)
{

    if (root == NULL)
    {
        return {};
    }
    queue<pair<TreeNode<int> *, pair<int, int>>> q;
    q.push({root, {0, 0}});
    map<int, map<int, multiset<int>>> mp;

    while (!q.empty())
    {

        TreeNode<int> *node = q.front().first;
        int vert = q.front().second.first;
        int level = q.front().second.second;

        q.pop();

        mp[vert][level].insert(node->data);

        if (node->left)
        {
            q.push({node->left, {vert - 1, level + 1}});
        }
        if (node->right)
        {
            q.push({node->right, {vert + 1, level + 1}});
        }
    }
    vector<int> ans;
    for (auto v : mp)
    {
        for (auto it : v.second)
        {
            ans.insert(ans.end(), it.second.begin(), it.second.end());
        }
    }

    return ans;
}