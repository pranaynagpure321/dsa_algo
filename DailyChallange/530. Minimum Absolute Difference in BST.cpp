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
    int res = INT_MAX;
    int prev = INT_MAX;
    vector<int> ans;
    void dfs(TreeNode* root)
    {
        if(root == NULL ) return ;
        if(root->left !=NULL)
        dfs(root->left);
        res = min(res, abs(prev - root->val) );
        prev = root->val;
        if(root->right != NULL)
        dfs(root->right);
       
    }

    int getMinimumDifference(TreeNode* root) {
        dfs(root);
        return res;
    }
};
