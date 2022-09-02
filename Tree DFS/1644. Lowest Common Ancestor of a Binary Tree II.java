/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    
    boolean isExistp= false;                           // to check if root exist
    boolean isExistq = false;
   
    public TreeNode dfs(TreeNode root, TreeNode p , TreeNode q  )
    {
        if(root == null) return null ;

        TreeNode left = dfs(root.left,p,q );
        TreeNode right = dfs(root.right,p,q);            
        
        if(root == p)                                       //since we need to return after traversal this condition are here
        {
           isExistp = true;                                 // once p or q is found return from there
           return root;
        }
        if(root == q)
        {
           isExistq = true;
           return root;
        }
        
        if( left!= null && right != null) return root;         //if left and right are not null that means this is command ancestor
        
        if(left == null) return right;                        //if left is null means both occure on rigth 
         
        return left;                                          //else both occure on left
    }
    
    
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        
        isExistp =false;
        isExistq = false;
       
        TreeNode ans = dfs(root,p,q);
        
        if(!isExistp ||  !isExistq) return null;
        
      
      // time O(n)
      // stack O(N) auxillary      
        return ans;
        
    }
}
