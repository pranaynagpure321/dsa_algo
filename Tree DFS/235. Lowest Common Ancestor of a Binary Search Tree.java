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
     
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        
         
        if( p.val > root.val && q.val > root.val)      //if both values greater then move right
            return lowestCommonAncestor(root.right, p ,q);  
        
        else if( p.val < root.val && q.val < root.val)     // if both values small then move left
            return lowestCommonAncestor(root.left, p ,q);
        
      
      
        //time O(n)
        //space O(n) recursion stack
        else return root;         // else we have found splt point
         
    }
}
