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
    
    
    //property : inorder traversal of BST gives natural sorted order
    ArrayList<Integer> list= new ArrayList<Integer>();
    public void inorder(TreeNode root)
    {
        if(root == null) return ;
        
        inorder(root.left);
        list.add(root.val);
        inorder(root.right);
    }
    public int kthSmallest(TreeNode root, int k) {
        
        
        inorder(root);
        //time O(N)
        return list.get(k-1);
    }
}
