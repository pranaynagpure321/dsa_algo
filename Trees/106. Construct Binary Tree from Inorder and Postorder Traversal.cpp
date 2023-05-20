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
    map<int,int> in;
    int postidx;

    TreeNode* dfs(vector<int>& post, int left, int right)
    {
        if(left > right) return NULL;

        int ele = post[postidx--];

        TreeNode *root = new TreeNode(ele);

        root->right = dfs(post,in[ele]+1, right);
        root->left = dfs(post, left , in[ele]-1);
        return root;
    }


    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
        for(int i =0 ;i< inorder.size() ;++i)
        {
            in[inorder[i]]=i;
        }
        postidx = inorder.size()-1;

        return dfs(postorder,0, inorder.size()-1);
    }
};
