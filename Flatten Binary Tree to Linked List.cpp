#include <bits/stdc++.h>
TreeNode<int> *flattenBinaryTree(TreeNode<int> *root)
{
    if (root == NULL)
    {
        return NULL;
    }

    stack<TreeNode<int> *> st;
    st.push(root);
    TreeNode<int> *prev = NULL;

    while (!st.empty())
    {
        TreeNode<int> *node = st.top();
        st.pop();

        if (node->right)
        {
            st.push(node->right);
        }
        if (node->left)
        {
            st.push(node->left);
        }

        if (prev != NULL)
        {
            prev->right = node;
            prev->left = NULL;
        }

        prev = node;
    }

    return root;
}