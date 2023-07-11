#include <bits/stdc++.h>
/**********************************************************

    Following is the Binary Tree Node structure:

    template <typename T>
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
            if (left)
                delete left;
            if (right)
                delete right;
        }
    };
***********************************************************/
void inorder(BinaryTreeNode<int> *root, vector<int> &ans)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left, ans);
    ans.push_back(root->data);
    inorder(root->right, ans);
}

bool pairSumBst(BinaryTreeNode<int> *root, int k)
{

    vector<int> ans;
    inorder(root, ans);
    sort(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++)
    {
        int l = i + 1, r = ans.size() - 1;
        while (l <= r)
        {

            int mid = l + (r - l) / 2;
            if (ans[i] + ans[mid] == k)
            {
                return true;
            }
            else if (ans[i] + ans[mid] > k)
            {
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
    }
    return false;
}