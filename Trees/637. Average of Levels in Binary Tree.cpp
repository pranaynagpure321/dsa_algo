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
 *
 
 637. Average of Levels in Binary Tree
Easy

3238

251
Add to List
Share
Given the root of a binary tree, return the average value of the nodes on each level in the form of an array. Answers within 10-5 of the actual answer will be accepted.

Example 1:
Input: root = [3,9,20,null,null,15,7]
Output: [3.00000,14.50000,11.00000]
Explanation: The average value of nodes on level 0 is 3, on level 1 is 14.5, and on level 2 is 11.
Hence return [3, 14.5, 11].*/


class Solution {
public:
    void dfs(TreeNode *root , int level, vector<vector<int>> &ans)
    {
        if(root == NULL) return;
        
        if(level >= ans.size())
            ans.push_back(vector<int>());
        
        ans[level].push_back(root->val);
        
        dfs(root->left,level+1,ans);
        dfs(root->right,level+1,ans);
        
    }
    vector<double> averageOfLevels(TreeNode* root) {
        vector<vector<int>> temp;
        dfs(root,0,temp);
        
        vector<double> ans;
        for(auto &v : temp)
        {
            double t =0;
            for(int i = 0 ; i< v.size() ; i++)
            {
                t+=(double) v[i];
            }
            t /= (double)v.size();
            
            ans.push_back(t);
        }
        return ans;
        
    }
};
