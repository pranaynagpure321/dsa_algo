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
    bool dfs(TreeNode* root, int targetSum)
    {
       
       if(root->left == NULL and root->right == NULL and targetSum-root->val == 0) return true;
        
       if( root->left != NULL  and dfs(root->left , targetSum -root->val))
           return true;
        
        if(root->right != NULL  and dfs(root->right , targetSum -root->val))
           return true;
        
        return false;
    }
    
    bool hasPathSum(TreeNode* root, int targetSum) {
        
        
       
        if(root == NULL) return false;
        
       // if(targetSum < root->val) return false;
        
        bool ans = dfs(root,targetSum);
        
        return ans;
    }
};
