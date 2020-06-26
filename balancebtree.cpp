/*

Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as:

a binary tree in which the left and right subtrees of every node differ in height by no more than 1.

 

Example 1:

Given the following tree [3,9,20,null,null,15,7]:

    3
   / \
  9  20
    /  \
   15   7
Return true.

Example 2:

Given the following tree [1,2,2,3,3,null,null,4,4]:

       1
      / \
     2   2
    / \
   3   3
  / \
 4   4
Return false.

*/


class Solution {
public:
    int height(TreeNode* root)
    {
        if(root==NULL)
            return NULL;
        return 1+max(height(root->left),height(root->right));
    }
    bool isBalanced(TreeNode* root) {
        int lh,rh;
        if(root==NULL)
            return 1;
        lh=height(root->left);
        rh=height(root->right);
        if(abs(lh-rh)<=1 && isBalanced(root->left) && isBalanced(root->right))
            return 1;
        return 0;
        
    }
};
