int findH(BinaryTreeNode<int> *root)

{

    if (!root)

        return 0;

    return 1 + max(findH(root->left), findH(root->right));
}

bool isBal(BinaryTreeNode<int> *root)

{

    if (!root)

        return true;

    int lh = findH(root->left);

    int rh = findH(root->right);

    if (abs(rh - lh) > 1)

        return false;

    bool lef = isBal(root->left);

    bool rig = isBal(root->right);

    if (!lef || !rig)

        return false;

    return true;
}

bool isBalancedBT(BinaryTreeNode<int> *root)
{

    // Write your code here.

    bool ans = isBal(root);

    return ans;
}