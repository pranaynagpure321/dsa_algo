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

//my solution
class Solution {
public:
    map<string, int> Lmp;
    map<string , int > Rmp;

    string getRevertedString(string s)
    {
        string ans ="";
        for(int i =0 ;i< s.length(); i++)
        {
            if(s[i] =='0') ans +="1";
            else ans +="0";   
        }
        return ans;
    }

    void dfs(TreeNode* root, string code )
    {   
        if(root == NULL) return ;

        if(code.length() > 0)
        {
            if(code[0] == '0')
            {
                Lmp[code] = root->val;
            }
            else 
                Rmp[code] = root->val;
        }

        dfs(root->left, code+"0") ;
        dfs(root->right, code+"1");
        
    }
    bool isSymmetric(TreeNode* root) {
        
        Lmp.clear();
        Rmp.clear();
        dfs(root,"");

        if(Lmp.size() != Rmp.size()) return false;

        for(auto &p : Lmp)
        {
            string tmp = getRevertedString(p.first);

            if(Rmp[tmp] != p.second ) return false;
        }
        //time O(n) time taken to solve 1:15
        return  true;
    }
};



//simple java solution
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

    public boolean isMirror(TreeNode t1,TreeNode t2)
    {
        if(t1 == null && t2== null) return true;
        if(t1 == null || t2== null) return false;
        return (t1.val == t2.val) && isMirror(t1.right, t2.left) && isMirror(t2.left, t1.right);

    }
    public boolean isSymmetric(TreeNode root) {
        return isMirror(root,root);
    }
}
