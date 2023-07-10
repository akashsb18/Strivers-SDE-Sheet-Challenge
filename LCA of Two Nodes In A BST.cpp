TreeNode<int> *LCAinaBST(TreeNode<int> *root, TreeNode<int> *p, TreeNode<int> *q)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data > p->data && root->data > q->data)
    {
        return LCAinaBST(root->left, p, q);
    }
    if (root->data < p->data && root->data < q->data)
    {
        return LCAinaBST(root->right, p, q);
    }
    if ((root->data >= p->data && root->data <= q->data) || (root->data <= p->data && root->data >= q->data))
    {
        return root;
    }
    else
    {
        return NULL;
    }
}