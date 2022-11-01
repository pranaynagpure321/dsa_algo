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
 *
 preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
Output: [3,9,20,null,null,15,7]


traverse left of inrder for left tree and traverse right for right tree in inorder array index */

class Solution {
public:
    
    map<int, int> in;
    int preIdx =0;
    TreeNode* dfs(vector<int>& preorder ,  int left, int right)
    {
        if(left > right) return NULL;
        
        int ele = preorder[preIdx++];
        
        TreeNode *root = new TreeNode(ele);
        
        root->left = dfs(preorder, left,in[ele]-1);
        root->right = dfs(preorder, in[ele]+1, right);
        
        return root;
        
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        preIdx =0;
        in.clear();
        for(int i =0; i< inorder.size(); ++i)
            in[inorder[i]]=i;
        
       return dfs(preorder, 0 ,preorder.size()-1); 
    }
};
