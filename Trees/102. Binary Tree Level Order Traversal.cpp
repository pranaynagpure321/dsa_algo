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
102. Binary Tree Level Order Traversal
Medium

10140

197

Add to List

Share
Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).
Example 1:
Input: root = [3,9,20,null,null,15,7]
Output: [[3],[9,20],[15,7]]*/


class Solution {
public:
    
    void dfs(TreeNode *root , int level, vector<vector<int>> &ans)
    {
        if(root == NULL) return;
        
        if(level >= ans.size())
            ans.push_back(vector<int>());
        
        ans[level].push_back(root->val);
        
        dfs(root->left,level+1,ans);
        dfs(root->right,level+1,ans);
        
    }
    
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        vector<vector<int>> ans;
        dfs(root,0,ans);
        return ans;
        
    }
};
