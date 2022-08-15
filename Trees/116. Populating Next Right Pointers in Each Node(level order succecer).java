/*116. Populating Next Right Pointers in Each Node
Medium
 
Add to List
Share
You are given a perfect binary tree where all leaves are on the same level, and every parent has two children. The binary tree has the following definition:
Initially, all next pointers are set to NULL.

Example 1:

Input: root = [1,2,3,4,5,6,7]
Output: [1,#,2,3,#,4,5,6,7,#]
Explanation: Given the above perfect binary tree (Figure A), your function should populate each next pointer to point to its next right node, just like in Figure B. The serialized output is in level order as connected by the next pointers, with '#' signifying the end of each level.*/


/*
// Definition for a Node.
class Node {
    public int val;
    public Node left;
    public Node right;
    public Node next;

    public Node() {}
    
    public Node(int _val) {
        val = _val;
    }

    public Node(int _val, Node _left, Node _right, Node _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};
*/

class Solution {
    public Node connect(Node root) {
        
        Queue<Node> q = new LinkedList<Node>();
        
        if(root == null ) return root;
        
        q.add(root);
        
        while(!q.isEmpty())
        {
            int size = q.size();
            
            for(int i =0 ;i< size ; i++)
            {
                Node node = q.poll();
                
                if(i< size-1)   // to link successor node
                node.next = q.peek();
                
                if(node.left != null )  q.add(node.left);
                
                if(node.right != null) q.add(node.right);
            }
        }
        
        return root;
        
    }
}
