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
    int res = INT_MIN;
    int dfs(TreeNode* root)
    {
        if(root == NULL) return -99999;

        int left = dfs(root->left);
        int right = dfs(root->right);

        res = max(res, left+right+root->val);
        res = max(res, max(left,right));

        return max(root->val,max(left+root->val , right+root->val)) ;
    }

    int maxPathSum(TreeNode* root) {
        res =INT_MIN;
        res = max(res,dfs(root));
        return res;
    }
};
