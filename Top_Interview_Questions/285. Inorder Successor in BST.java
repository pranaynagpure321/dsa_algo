TreeNode* succesor(TreeNode *root, TreeNode *p)
    {
        if(root == NULL) return NULL;

        if(root->val <= p->val){
          return succesor(root->right,p);
         
        }
        else
        {
            TreeNode *left = succesor(root->left,p);
            if(left!= NULL) return left;
            else return root;
        }

        return NULL;
    }
public TreeNode predecessor(TreeNode root, TreeNode p) {
  if (root == null)
    return null;

  if (root.val >= p.val) {
    return predecessor(root.left, p);
  } else {
    TreeNode right = predecessor(root.right, p);
    return (right != null) ? right : root;
  }
}
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        
         
        return succesor(root,p);
    }
