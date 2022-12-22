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

    TreeNode* dfs(TreeNode* root)
    {
        if(root == NULL) return root;

       TreeNode* left = dfs(root->left);
       TreeNode* right = dfs(root->right);

       root->right = left;
       root->left = right;

       return root; 
      
    }
    TreeNode* invertTree(TreeNode* root) {
        
        if(root == NULL) return root;
        queue<TreeNode *> q;
        
        q.push(root);

        while(!q.empty())
        {    
           TreeNode * cur = q.front(); q.pop();
           TreeNode *tmp  = cur->left;
           cur->left= cur->right;
           cur->right = tmp;
             
           if(cur->left != NULL)
            q.push(cur->left);

           if(cur->right != NULL)
            q.push(cur->right);  
        }
        return root;
    }
};
