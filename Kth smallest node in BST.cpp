#include <bits/stdc++.h>
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

void f(TreeNode<int> *root, vector<int> &temp)
{
    if (root == NULL)
    {
        return;
    }

    temp.push_back(root->data);

    if (root->left)
    {
        f(root->left, temp);
    }
    if (root->right)
    {
        f(root->right, temp);
    }
}

int kthSmallest(TreeNode<int> *root, int k)
{
    vector<int> nodes;
    f(root, nodes);

    sort(nodes.begin(), nodes.end());

    return nodes[k - 1];
}