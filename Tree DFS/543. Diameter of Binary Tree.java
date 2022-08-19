/*
543. Diameter of Binary Tree
Easy

Add to List

Share
Given the root of a binary tree, return the length of the diameter of the tree.

The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.

The length of a path between two nodes is represented by the number of edges between them.
Example 1:


Input: root = [1,2,3,4,5]
Output: 3
Explanation: 3 is the length of the path [4,2,1,3] or [5,2,1,3].
Example 2:
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
 
 int diameterOfBinaryTree(TreeNode* root) {
        int d=0;
        rec(root, d);
        return d;
    }
    
    int rec(TreeNode* root, int &d) {
        if(root == NULL) return 0;
        int ld = rec(root->left, d);
        int rd = rec(root->right, d);
        d=max(d,ld+rd);
        return max(ld,rd)+1;
    }
 */
class Solution {
    public int dfs(TreeNode root )
    {
        if(root == null)  return  0;

        int max = 0;  
        int left = 1+ dfs(root.left);
        int right =  1+ dfs(root.right);
        return Math.max(left , right);
    }
    
    public int diameterOfBinaryTree(TreeNode root) {
    
        if(root == null)  return  0;
      
        int  max = 0;
        max  =   dfs(root.left) + dfs(root.right) ;
        max =  Math.max(diameterOfBinaryTree(root.left) , max);
        max = Math.max(diameterOfBinaryTree(root.right) , max);
        return max;
        
        
    }
}
