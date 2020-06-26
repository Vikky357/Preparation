/*

Binary Tree Zigzag Level Order Traversal
Medium

1952

99

Add to List

Share
Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its zigzag level order traversal as:
[
  [3],
  [20,9],
  [15,7]
]

*/


class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root==NULL)
            return vector<vector<int>>{};
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);
        bool lr=true;
        while(!q.empty())
        {
            int size=q.size();
            vector<int> ians(size);
            for(int i=0;i<size;i++)
            {
                TreeNode* temp=q.front();
                q.pop();
                int index=(lr)?i:(size-i-1);
                ians[index]=temp->val;
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
            }
            ans.push_back(ians);
            lr=!lr;
            
        }
        return ans;
        }
};
