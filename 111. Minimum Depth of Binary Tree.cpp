/*111. Minimum Depth of Binary Tree
Easy

4629

982

Add to List

Share
Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.

Note: A leaf is a node with no children.

 

Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: 2*/



/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int dfs(TreeNode* root  )
    {
      
      if(root == NULL) return 0;
        
        int left = 1+ dfs(root->left);
        int right = 1+dfs(root->right);
        
        if(root->left == NULL and root->right != NULL)
        return right;
        
        else if(root->left != NULL and root->right == NULL)
            return left;
        
        return min(left,right);
    }
    
    int minDepth(TreeNode* root) {
        
        
        int ans = dfs(root);
        
        return ans;
    }
};
