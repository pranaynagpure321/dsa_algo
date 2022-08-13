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
     void dfs(TreeNode *root , int level, vector<vector<int>> &ans)
    {
        if(root == NULL) return;
        
        if(level >= ans.size())
            ans.push_back(vector<int>());
        
        ans[level].push_back(root->val);
        
        dfs(root->left,level+1,ans);
        dfs(root->right,level+1,ans);
        
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        dfs(root,0,ans);
        
        for( int i =1 ;i<ans.size() ;i+=2)
        {
            reverse(ans[i].begin(), ans[i].end());
        }
        
        
        return ans;
    }
};
