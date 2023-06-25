#include <bits/stdc++.h>
/**********************************************************

    Following is the Binary Tree Node class structure:

    template <typename T>

    class BinaryTreeNode {
    public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

***********************************************************/

bool identicalTrees(BinaryTreeNode<int> *p, BinaryTreeNode<int> *q)
{
    if (p == NULL and q == NULL)
    {
        return true;
    }
    if (p == NULL and q != NULL)
    {
        return false;
    }
    if (p != NULL and q == NULL)
    {
        return false;
    }

    if (p->data != q->data)
    {
        return false;
    }

    bool checkL = identicalTrees(p->left, q->left);
    bool checkR = identicalTrees(p->right, q->right);

    return (checkL and checkR);
}