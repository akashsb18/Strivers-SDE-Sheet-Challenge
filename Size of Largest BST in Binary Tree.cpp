class Info
{
public:
    int maxi;
    int mini;
    bool isValid;
    int size;

public:
    Info()
    {
        maxi = INT_MIN;
        mini = INT_MAX;
        isValid = true;
        size = 0;
    }
};

Info *solver(TreeNode<int> *root, int &ans)
{
    if (root == NULL)
    {
        Info *node = new Info;
        return node;
    }

    Info *left = solver(root->left, ans);
    Info *right = solver(root->right, ans);

    Info *head = new Info;
    head->maxi = max(right->maxi, root->data);
    head->mini = min(left->mini, root->data);
    head->size = left->size + right->size + 1;

    if (left->isValid && right->isValid && (root->data > left->maxi && root->data < right->mini))
    {
        head->isValid = true;
    }
    else
    {
        head->isValid = false;
    }

    if (head->isValid)
        ans = max(ans, head->size);

    return head;
}

int largestBST(TreeNode<int> *root)
{

    int maxAns = 0;
    Info *result = solver(root, maxAns);

    return maxAns;
}