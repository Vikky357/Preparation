/*

Symmetric Tree
Easy

4017

94

Add to List

Share
Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree [1,2,2,3,4,4,3] is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3
 

But the following [1,2,2,null,3,null,3] is not:

    1
   / \
  2   2
   \   \
   3    3
 

Follow up: Solve it both recursively and iteratively.


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
