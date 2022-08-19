/*1650. Lowest Common Ancestor of a Binary Tree III
Medium
 
Add to List

Share
Given two nodes of a binary tree p and q, return their lowest common ancestor (LCA).

Each node will have a reference to its parent node. The definition for Node is below:

class Node {
    public int val;
    public Node left;
    public Node right;
    public Node parent;
}
According to the definition of LCA on Wikipedia: "The lowest common ancestor of two nodes p and q in a tree T is the lowest node that has both p and q as descendants (where we allow a node to be a descendant of itself)."

Example 1:
Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
Output: 3
Explanation: The LCA of nodes 5 and 1 is 3.
Example 2:

 */

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};

//optimized but slow solution
 Node* lowestCommonAncestor(Node* p, Node * q) {
        Node *a = p ,*b = q;
        
        while(a!=b)
        {
            a = a == NULL ? p : (*a).parent;
            b = b == NULL ? q : b->parent;
        }
        
        return a;
    }
*/

class Solution {
public:
    
    Node* lowestCommonAncestor(Node* p, Node * q) {
        map<int, int> visi;
        while(p != NULL)
        {
            visi[p->val]++;
            p= p-> parent;
        }
        
        while(visi.find(q->val) == visi.end())
        {
            q = q->parent;
        }
        
        return q;
    }
};
