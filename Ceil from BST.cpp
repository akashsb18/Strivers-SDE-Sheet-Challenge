#include <bits/stdc++.h>
/************************************************************

    Following is the TreeNode class structure:

    class BinaryTreeNode {
    public:
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }

        ~BinaryTreeNode() {
            if (left) {
              delete left;
            }
            if (right) {
              delete right;
            }
        }
    };

************************************************************/
void Search(BinaryTreeNode<int> *root, int x, int &ans)
{
    if (root == NULL)
    {
        return;
    }

    if (root->data == x)
    {
        ans = x;
        return;
    }

    if (root->data > x)
    {
        ans = root->data;
        Search(root->left, x, ans);
        return;
    }

    if (root->data < x)
    {
        Search(root->right, x, ans);
        return;
    }
}

int findCeil(BinaryTreeNode<int> *root, int x)
{
    if (root == NULL)
    {
        return -1;
    }

    int ans = -1;
    Search(root, x, ans);
    return ans;
}