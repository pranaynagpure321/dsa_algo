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

    void dfs(TreeNode *root, int mx ,int mi)
    {
        if(root == NULL) return;

        int t = mx , t2 = mi;
        mx = max(mx,root->val);
        mi = min(mi,root->val);

        res = max(res, abs(mx-mi));
        dfs(root->left,mx,mi);
        dfs(root->right,mx,mi);

        mx =t; mi =t2;

    }

    int maxAncestorDiff(TreeNode* root) {
        
        res = INT_MIN;
        dfs(root,INT_MIN,INT_MAX);

        return res;
    }
};
