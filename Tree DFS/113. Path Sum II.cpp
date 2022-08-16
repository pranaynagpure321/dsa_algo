/*
113. Path Sum II
Medium
 

Add to List

Share
Given the root of a binary tree and an integer targetSum, return all root-to-leaf paths where the sum of the node values in the path equals targetSum. Each path should be returned as a list of the node values, not node references.
A root-to-leaf path is a path starting from the root and ending at any leaf node. A leaf is a node with no children.
Example 1:
Input: root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
Output: [[5,4,11,2],[5,8,4,5]]
Explanation: There are two paths whose sum equals targetSum:
5 + 4 + 11 + 2 = 22
5 + 8 + 4 + 5 = 22
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
    void dfs(TreeNode* root, int targetSum,vector<vector<int>> & ans, vector<int> temp )
    {
        if(root == NULL  ) return ;
        
        if(root->left == NULL and root->right == NULL and targetSum-root->val ==0)
        {
            temp.push_back(root->val);
            ans.push_back(temp);
        }

        temp.push_back(root->val);
        dfs(root->left , targetSum - root->val ,ans ,temp);
        
        dfs(root->right , targetSum - root->val,ans , temp);
        
        temp.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        
        vector<vector<int>>  ans;
        
        dfs(root,targetSum , ans, vector<int>());
        
        return ans;
    }
};
