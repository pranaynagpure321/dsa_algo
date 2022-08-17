/* 3 cases take root dont take root
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
   
    
    public int dfs(TreeNode root,long curr )
    { 
        if(root == null) return 0;
        
        int count =0;
        if(curr == root.val ) { count++; }

        count += dfs(root.left, curr-root.val);
        count += dfs(root.right, curr-root.val);
        
        return count;
    }
    
    public int pathSum(TreeNode root, int targetSum) {
        
        if(root== null) return 0;
      
        
        return pathSum(root.left ,targetSum) + dfs(root,targetSum) + pathSum(root.right, targetSum);
        
    }
}
