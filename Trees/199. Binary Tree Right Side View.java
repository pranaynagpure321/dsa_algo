/*
199. Binary Tree Right Side View
Medium
Add to List
Share
Given the root of a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.
Example 1:
Input: root = [1,2,3,null,5,null,4]
Output: [1,3,4]
Example 2:

Input: root = [1,null,3]
Output: [1,3]
Example 3:

Input: root = []
Output: []
*
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
    public List<Integer> rightSideView(TreeNode root) {
        
        if(root == null) return new ArrayList<Integer>();
       
        Queue<TreeNode> q = new LinkedList<>();
        var ans = new ArrayList<Integer>();
        
        q.add(root);
        
        while(!q.isEmpty())
        {
            int size = q.size();
            
            for( int i = 0 ;i< size ;i++)
            {
                if(i == size-1)
                    ans.add(q.peek().val);
                
                
                TreeNode node =  q.poll();
                
                if(node.left != null)
                q.add(node.left);
                
                if(node.right != null)
                    q.add(node.right);
            }
        }
        return ans;
        
    }
}
