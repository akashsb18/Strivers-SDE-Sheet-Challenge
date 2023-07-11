#include <bits/stdc++.h>
/************************************************************
    Following is the Binary Search Tree node structure

    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
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

int KthLargestNumber(TreeNode<int> *root, int k)
{
    vector<int> ans;
    f(root, ans);
    sort(ans.rbegin(), ans.rend());

    // for(auto it:ans){
    //     cout<<it<<" ";
    // }

    if (k > ans.size())
    {
        return -1;
    }

    return ans[k - 1];
}
