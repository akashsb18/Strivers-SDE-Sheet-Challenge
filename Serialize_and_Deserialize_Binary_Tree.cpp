
#include <sstream>
string serializeTree(TreeNode<int> *root)
{
    if (root == NULL)
    {
        return "";
    }
    string ans = "";

    queue<TreeNode<int> *> q;
    q.push(root);

    while (!q.empty())
    {
        TreeNode<int> *node = q.front();
        q.pop();
        if (node == NULL)
        {
            ans += "#,";
        }
        else
        {
            ans += to_string(node->data) + ",";
        }
        if (node)
        {
            q.push(node->left);
            q.push(node->right);
        }
    }
    return ans;
}

TreeNode<int> *deserializeTree(string &data)
{
    if (data.size() == 0)
    {
        return NULL;
    }
    stringstream s(data);
    string str;
    getline(s, str, ',');
    TreeNode<int> *root = new TreeNode<int>(stoi(str));
    queue<TreeNode<int> *> q;
    q.push(root);
    while (!q.empty())
    {
        TreeNode<int> *node = q.front();
        q.pop();

        getline(s, str, ',');
        if (str == "#")
        {
            node->left = NULL;
        }
        else
        {
            TreeNode<int> *leftNode = new TreeNode<int>(stoi(str));
            node->left = leftNode;
            q.push(leftNode);
        }
        getline(s, str, ',');
        if (str == "#")
        {
            node->right = NULL;
        }
        else
        {
            TreeNode<int> *rightNode = new TreeNode<int>(stoi(str));
            node->right = rightNode;
            q.push(rightNode);
        }
    }

    return root;
}
