 
class Solution {
public:
  TreeNode *res = NULL, *t= res;

    void dfs(TreeNode *root)
    {
        if(root == NULL) return   ;

        TreeNode * node = new TreeNode(root->val);
        node->left = NULL;

        t->right = node;
        t = t->right;

        dfs(root->left);
        dfs(root->right);

    }
    void flatten(TreeNode* root) {
        
        if(root == NULL) return  ;
        res = new TreeNode(-1);
        t= res;
        dfs(root);
        *root = *(res->right);
        return  ;
    }
};




 // solution without the O(N) space
class Solution {
    public void flatten(TreeNode root) {
        
        if(root == null) return;

        TreeNode node = root;

        while(node != null)
        {
            // If the node has a left child
            while(node.left != null)
            {
                // Find the rightmost node
                TreeNode rightmost = node.left;
                while(rightmost.right != null)
                {
                    rightmost = rightmost.right;
                }

                rightmost.right = node.right;
                node.right = node.left;
                node.left = null;
            }
            node =node.right;
        }
    }
}
