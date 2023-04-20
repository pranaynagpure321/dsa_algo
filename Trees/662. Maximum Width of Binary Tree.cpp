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
    int widthOfBinaryTree(TreeNode* root) {
        
        if(root == NULL) return 0;

        queue<pair<TreeNode*, int>> q;

        q.push({root,0});
        int res =1;

        while(!q.empty())
        {
            int start = q.front().second;
            int end = q.back().second;
            res = max(res, (end- start ) +1);
            int size = q.size();
            
            TreeNode *last = NULL;
            int col_idx =0;
            for(int i =0 ;i< size ;i++)
            {
                last = q.front().first;
                col_idx= q.front().second-start;    // this in imp because if not done it will give overflow
                q.pop();

                if(last->left != NULL)
                q.push({last->left, 2LL*col_idx+1});

                if(last->right!= NULL)
                q.push({last->right , 2LL*col_idx+2});

            }
        }

        return res;
    }
};
