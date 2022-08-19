// this is incomplete solution to above problem



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
class Solution {
public:
    
    void insert(int col ,vector<vector<int> > &res, int val )
    {
        if(col < 0)
        {
            col = abs(col);
            
            while(col+1> res.size()) res.push_back({});
            
            res[col].push_back(val);
        }
        else
        {
            
            while(col+1> res.size()) res.push_back({});
            
            res[col].push_back(val);
        }
    }
    
    void dfs(TreeNode * root , int col , vector<vector<int> > &neg,vector<vector<int> >& pos)
    {
        if(root == NULL) return;
        
        dfs(root->left, col-1, neg, pos);
        
        if(col < 0 )
        {
            insert(col, neg,root->val);
        }
        else
        {
             insert(col, pos,root->val);
        }
        
        dfs(root->right,col+1, neg,pos);
        
        
    }
    
    void reorderPositive(vector<vector<int> > &pos)
    {
        
        for( int i =0 ; i< pos.size() ; i++)
        {
            
            if(pos[i].size() <2) continue;
            
            
            int j =0 , k = pos[i].size()-1;
            
            while(j < k)
            {
                int temp = pos[i][j];
                pos[i][j] = pos[i][k];
                pos[i][k] = temp;
                j++; k--;
            }
            
        }
        
    }
     
    vector<vector<int>> verticalOrder(TreeNode* root) {
        
        
        vector<vector<int> > neg;
        vector<vector<int> > pos;
        int col =0;
        
        dfs(root,col,neg,pos);
        
        reverse(neg.begin(), neg.end());
        reorderPositive(pos);
        
        vector<vector<int> > res;
        
        for(int i =0 ;i< neg.size() ; i++)
            if(neg[i].size() >=1)
            {
                res.push_back(neg[i]);
            }
            
        for(int i =0 ;i< pos.size() ; i++)
          if(pos[i].size() >=1)
            {
                res.push_back(pos[i]);
            }
        
        
        return res;
    }
};
