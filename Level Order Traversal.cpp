#include <bits/stdc++.h>
/************************************************************

    Following is the BinaryTreeNode class structure

    template <typename T>
    class BinaryTreeNode {
       public:
        T val;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
vector<int> getLevelOrder(BinaryTreeNode<int> *root)
{
    if (!root)
    {
        return {};
    }
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    vector<int> ans;
    while (!q.empty())
    {

        BinaryTreeNode<int> *node = q.front();
        q.pop();
        ans.push_back(node->val);
        if (node and node->left)
        {
            q.push(node->left);
        }
        if (node and node->right)
        {
            q.push(node->right);
        }
    }

    return ans;
}