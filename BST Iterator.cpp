#include <bits/stdc++.h>

class BSTiterator
{
public:
    vector<int> ans;

    void levelOrder(TreeNode<int> *root)
    {
        if (!root)
        {
            return;
        }
        queue<TreeNode<int> *> q;
        q.push(root);
        while (!q.empty())
        {

            TreeNode<int> *node = q.front();
            q.pop();
            ans.push_back(node->data);
            if (node and node->left)
            {
                q.push(node->left);
            }
            if (node and node->right)
            {
                q.push(node->right);
            }
        }
    }

    BSTiterator(TreeNode<int> *root)
    {
        levelOrder(root);
    }

    int next()
    {
        sort(ans.begin(), ans.end());
        int res = 0;
        if (!ans.empty())
        {
            res = ans[0];
            ans.erase(ans.begin());
        }
        return res;
    }

    bool hasNext()
    {
        if (ans.size() == 0)
        {
            return false;
        }
        return true;
    }
};

/*
    Your BSTIterator object will be instantiated and called as such:
    BSTIterator iterator(root);
    while(iterator.hasNext())
    {
       print(iterator.next());
    }
*/