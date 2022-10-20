/**
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
    
    
    TreeNode dfs(int[] nums, int i , int j )
    {
        if(i>j)
            return null;
        int mid = (i+j)>>1;
        TreeNode root = new TreeNode(nums[mid],null,null);
        root.left = dfs(nums, i,mid-1  );
        root.right =  dfs(nums,mid+1,j );
        
        return root;
    }

    public TreeNode sortedArrayToBST(int[] nums) {
        int n = nums.length;
        if(n==0)
            return null;
        return dfs(nums,0,n-1);
    }
}
