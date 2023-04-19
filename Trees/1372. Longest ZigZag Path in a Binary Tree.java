class Solution {
    int max=0;
    public int longestZigZag(TreeNode root) {
       if (root == null) return -1;
        max = 0;
        helper(root.right, 1, true);
        helper(root.left, 1, false);
        return max;   
    }
     private  void helper(TreeNode root, int step, boolean isRight) {
        if (root == null) return;
        max = Math.max(max, step);
        if (isRight) {
            helper(root.left, step + 1, false);
            helper(root.right, 1, true);
        } else {
            helper(root.right, step + 1, true);
            helper(root.left, 1, false);
        }
    }
}


//c++ with pairs
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
    pair<int,int> longestpath(TreeNode * root, int& ans)
    {
        if(root == NULL) return {0,0};

        auto  p1 = longestpath(root->left, ans);
        ans = max(ans, 1+p1.second);
        auto p2 = longestpath(root->right, ans);
        ans = max(ans,1+ p2.first);
        return {1+p1.second, 1+p2.first };
    }

    int longestZigZag(TreeNode* root) {
        
        if(root == NULL) return 0;
        if(root->left == NULL and root->right == NULL) return 0;

        int ans =0;
        longestpath(root,ans );

        return ans-1;
    }
};
