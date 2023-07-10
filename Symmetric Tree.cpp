/*****************************************************

    Following is the Binary Tree node structure:

    class BinaryTreeNode {
        public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~BinaryTreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

******************************************************/

bool check(BinaryTreeNode<int> *p, BinaryTreeNode<int> *q)
{

    if (!p or !q)
    {
        return p == q;
    }

    if (p->data != q->data)
    {
        return false;
    }

    return check(p->left, q->right) and check(p->right, q->left);
}

bool isSymmetric(BinaryTreeNode<int> *root)
{

    if (!root)
    {
        return true;
    }

    return check(root->left, root->right);
}