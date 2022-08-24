/*2096. Step-By-Step Directions From a Binary Tree Node to Another
Medium

1462

82

Add to List

Share
You are given the root of a binary tree with n nodes. Each node is uniquely assigned a value from 1 to n. You are also given an integer startValue representing the value of the start node s, and a different integer destValue representing the value of the destination node t.

Find the shortest path starting from node s and ending at node t. Generate step-by-step directions of such path as a string consisting of only the uppercase letters 'L', 'R', and 'U'. Each letter indicates a specific direction:

'L' means to go from a node to its left child node.
'R' means to go from a node to its right child node.
'U' means to go from a node to its parent node.
Return the step-by-step directions of the shortest path from node s to node t.

 

Example 1:


Input: root = [5,1,2,3,null,6,4], startValue = 3, destValue = 6
Output: "UURL"
Explanation: The shortest path is: 3 → 1 → 5 → 2 → 6.
*/

class Solution {
   
    private boolean DFS(TreeNode currNode, StringBuilder path, int destVal) {
        if(currNode == null) return false;
        if(currNode.val == destVal) return true;
        if(DFS(currNode.left, path, destVal)) path.append("L");
        else if(DFS(currNode.right, path, destVal)) path.append("R");
        return path.length() > 0;
    }
    
    
    public String getDirections(TreeNode root, int startValue, int destValue) {
        
       
        StringBuilder startToRoot = new StringBuilder();
        StringBuilder endToRoot = new StringBuilder();
        
        DFS(root, startToRoot, startValue);
        DFS(root, endToRoot, destValue);
        
        int i = startToRoot.length(), j = endToRoot.length();
        int cnt = 0;
        while(i > 0 && j > 0 && startToRoot.charAt(i-1) == endToRoot.charAt(j-1)) {
            cnt++; i--; j--;
        }
        
        String sPath = "U".repeat(startToRoot.length() - cnt);
        String ePath = endToRoot.reverse().toString().substring(cnt, endToRoot.length());
        
        return sPath + ePath;
        
    }
}
