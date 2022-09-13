/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

/*95. Unique Binary Search Trees II
Medium

5314

345

Add to List

Share
Given an integer n, return all the structurally unique BST's (binary search trees), which has exactly n nodes of unique values from 1 to n. Return the answer in any order.

 

Example 1:


Input: n = 3
Output: [[1,null,2,null,3],[1,null,3,2],[2,1,3],[3,1,null,null,2],[3,2,null,1]]*/
class Solution {
public:
    
    
    //logic explained in video https://www.youtube.com/watch?v=mhCJgZWJlSI&ab_channel=CodingDecoded
    //basically we are itereating over the all the node which can be root nodes then we will geneate all the 
    //left as well as right sub tree for the given root 
    //after this we will return the list
    
     vector<TreeNode*> help(int start , int end  )
    {
        vector<TreeNode *> list;
        if(start > end)
        {
            list.push_back(NULL);  
            return list;
        }
        
        if(start == end)
        {
            list.push_back(new TreeNode(start));
            return list;
        }

        for (int i = start; i <=end ; ++i) {
            
            auto leftsubtrees = help(start,i-1);          //generate all the left subtrees
            auto rightsubtrees = help(i+1, end);          // generate all the right subtrees
            
            for( auto & lroot : leftsubtrees )
            {
                for(auto & rroot : rightsubtrees)
                {
                    TreeNode * root = new TreeNode(i, lroot, rroot);
                    list.push_back(root);
                }
            }
            
            
        }
        
        return list;
    }
    vector<TreeNode*> generateTrees(int n) {
        
       return help(1,n);
    }
};
