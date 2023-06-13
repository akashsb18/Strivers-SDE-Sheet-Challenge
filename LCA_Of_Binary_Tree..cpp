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
TreeNode<int> *path(TreeNode<int> *root, int p, int q)
{

    if (root == NULL)
    {
        return NULL;
    }

    if (root->data == p or root->data == q)
    {
        return root;
    }

    TreeNode<int> *right = path(root->right, p, q);
    TreeNode<int> *left = path(root->left, p, q);

    if (right == NULL)
    {
        return left;
    }
    else if (left == NULL)
    {
        return right;
    }
    return root;
}
int lowestCommonAncestor(TreeNode<int> *root, int p, int q)
{
    TreeNode<int> *ans = path(root, p, q);
    return ans->data;
}