#include <bits/stdc++.h>

void findPath(TreeNode<int> *node, vector<int> &ans, int x)
{

    if (!node)
    {
        return;
    }

    ans.push_back(node->data);

    if (node->data == x)
    {
        return;
    }

    if (node->left)
    {
        findPath(node->left, ans, x);
        if (ans.back() == x)
        {
            return;
        }
    }

    if (node->right)
    {
        findPath(node->right, ans, x);
        if (ans.back() == x)
        {
            return;
        }
    }

    ans.pop_back();
}

vector<int> pathInATree(TreeNode<int> *root, int x)
{
    vector<int> ans;
    findPath(root, ans, x);
    return ans;
}
