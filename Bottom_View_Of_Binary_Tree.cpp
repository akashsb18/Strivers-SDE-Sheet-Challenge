vector<int> bottomView(BinaryTreeNode<int> *root)
{
    queue<pair<BinaryTreeNode<int> *, int>> q;
    map<int, int> mp;
    vector<int> ans;
    q.push({root, 0});
    while (!q.empty())
    {
        BinaryTreeNode<int> *node = q.front().first;
        int vert = q.front().second;
        q.pop();

        mp[vert] = node->data;

        if (node->left)
        {
            q.push({node->left, vert - 1});
        }
        if (node->right)
        {
            q.push({node->right, vert + 1});
        }
    }
    for (auto it : mp)
    {
        ans.push_back(it.second);
    }
    return ans;
}
