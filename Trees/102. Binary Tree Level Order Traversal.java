/*102. Binary Tree Level Order Traversal

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
    public List<List<Integer>> levelOrder(TreeNode root) {
        
        List<List<Integer>> ans = new ArrayList< List<Integer>>();
        
        Queue<TreeNode> que = new LinkedList<TreeNode>();
        
        if(root == null) return ans;
        
        que.add(root);
        
        while(!que.isEmpty())
        {
            var level = new ArrayList<Integer>();
            int size = que.size();
            
            for(int i = 0; i < size ; i++)
            {
                TreeNode node = que.poll();
                
                if(node.left != null) que.add(node.left);
                if(node.right != null ) que.add(node.right);
                
                level.add(node.val);
                
            }
            
            ans.add(level);
            
        }
        
        
        return ans;
    }
}
