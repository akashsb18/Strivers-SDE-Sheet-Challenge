vector<int> getLeftView(TreeNode<int> *root)
{
    if (!root)
    {
        return {};
    }
    vector<int> v;
    queue<TreeNode<int> *> Q;
    Q.push(root);
    while (!Q.empty())
    {
        int size = Q.size();
        for (int i = 0; i < size; i++)
        {
            TreeNode<int> *t = Q.front();
            Q.pop();
            if (i == 0)
            {
                v.push_back(t->data);
            }
            if (t->left)
            {
                Q.push(t->left);
            }
            if (t->right)
            {
                Q.push(t->right);
            }
        }
    }
    return v;
}
