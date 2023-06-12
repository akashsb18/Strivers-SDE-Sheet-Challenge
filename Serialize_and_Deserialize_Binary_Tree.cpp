
#include <sstream>
string serializeTree(Node<int> *root)
{
    if (root == NULL)
    {
        return "";
    }
    string ans = "";

    queue<Node<int> *> q;
    q.push(root);

    while (!q.empty())
    {
        Node<int> *node = q.front();
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

Node<int> *deserializeTree(string &data)
{
    if (data.size() == 0)
    {
        return NULL;
    }
    stringstream s(data);
    string str;
    getline(s, str, ',');
    Node<int> *root = new Node<int>(stoi(str));
    queue<Node<int> *> q;
    q.push(root);
    while (!q.empty())
    {
        Node<int> *node = q.front();
        q.pop();

        getline(s, str, ',');
        if (str == "#")
        {
            node->left = NULL;
        }
        else
        {
            Node<int> *leftNode = new Node<int>(stoi(str));
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
            Node<int> *rightNode = new Node<int>(stoi(str));
            node->right = rightNode;
            q.push(rightNode);
        }
    }

    return root;
}
