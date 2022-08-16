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
    
    void dfs(TreeNode* root ,string curr, vector<string>& ans)
    {
        if(root != NULL)
        { 
            if(curr.length() == 0) 
                curr += to_string(root->val);
            else
              curr += "->" +to_string(root->val);
            
            if(root->left == NULL and root->right == NULL) 
                ans.push_back(curr );
            
            dfs(root->left,  curr  ,ans);
            dfs(root->right,  curr  ,ans); 
        }
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        
        vector<string> ans;
        
        dfs(root,"",ans);
        
        return ans;
    }
};
