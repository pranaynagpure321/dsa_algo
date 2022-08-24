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
    
    ArrayList<List<Integer>> list = new ArrayList<List<Integer>>();
    public int  dfs(TreeNode root)
    {
        if(root == null ) return 0;
        
        int left = 1 + dfs(root.left);
        int right = 1 + dfs(root.right);
        
        int index = Math.max(left, right);
        
        while(index > list.size()) { list.add(new ArrayList<>());}
        
        list.get(index-1).add(root.val);
        
        return index;
    }
    public List<List<Integer>> findLeaves(TreeNode root) {
        
        dfs(root);
        return list;
    }
}
