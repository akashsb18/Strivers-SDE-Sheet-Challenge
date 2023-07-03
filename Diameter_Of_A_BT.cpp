/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
    int getMax(TreeNode<int> *root,int &maxi){
        if(root==NULL){
            return 0;
        }
        int lh=getMax(root->left,maxi);
        int rh=getMax(root->right,maxi);

        maxi=max(maxi,lh+rh);

        return 1+max(lh,rh);

    }
int diameterOfBinaryTree(TreeNode<int> *root)
{
        if(root==NULL){
            return 0;
        }
        int maxi=-1e8;
        getMax(root,maxi);

        return maxi;
}
