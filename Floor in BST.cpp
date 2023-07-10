#include <bits/stdc++.h>
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
void traverse(TreeNode<int> *root, int X, int &ans)
{

    if (root == NULL)
    {
        return;
    }

    if (root->val > X)
    {
        traverse(root->left, X, ans);
    }
    if (root->val <= X)
    {
        ans = root->val;
        traverse(root->right, X, ans);
    }
}

int floorInBST(TreeNode<int> *root, int X)
{
    int ans = 0;
    traverse(root, X, ans);
    return ans;
}