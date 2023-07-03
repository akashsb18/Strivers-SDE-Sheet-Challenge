#include <bits/stdc++.h> 
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
    TreeNode<int> *build(vector<int>& preorder,int preStart,int preEnd,vector<int>& inorder,int inStart,int inEnd,map<int,int> &mp){
        if(preStart>preEnd or inStart>inEnd){
            return NULL;
        }

        TreeNode<int> *root=new TreeNode<int>(preorder[preStart]);

        int inRoot=mp[root->data];
        int numsLeft=inRoot-inStart;

        root->left=build(preorder,preStart+1,preStart+numsLeft,inorder,inStart,inRoot-1,mp);
        root->right=build(preorder,preStart+numsLeft+1,preEnd,inorder,inRoot+1,inEnd,mp);


        return root;
    }
TreeNode<int> *buildBinaryTree(vector<int> &inorder, vector<int> &preorder)
{
        map<int,int> mp;
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]]=i;
        }

        TreeNode<int> *root=build(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,mp);
        return root;
}