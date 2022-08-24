/**
366. Find Leaves of Binary Tree
Medium

 

Add to List

Share
Given the root of a binary tree, collect a tree's nodes as if you were doing this:

Collect all the leaf nodes.
Remove all the leaf nodes.
Repeat until the tree is empty.
 
Example 1:

Input: root = [1,2,3,4,5]
Output: [[4,5,3],[2],[1]]
Explanation:
[[3,5,4],[2],[1]] and [[3,4,5],[2],[1]] are also considered correct answers since per each level it does not matter the order on which elements are returned.
Example 2:

Input: root = [1]
Output: [[1]]
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
