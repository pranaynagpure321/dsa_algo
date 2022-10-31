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
   int d1[100001] = {}, d2[100001] = {};        // maintain two maximum on each level
    map<int, pair<int, int>> mp;               // to maintain  map<node, Pair<level, dept>>

    int help(TreeNode* root, int level)
    {
        if (root == NULL)
            return 0;

        int node = root->val;

        mp[node].first = level;

        int dept = 1 + max(help(root->left, level + 1), help(root->right, level + 1));
        mp[node].second = dept;
        if (dept > d1[level])
        {
            d2[level] = d1[level];
            d1[level] = dept;
        }
        else if (dept > d2[level])
        {
            d2[level] = dept;
        }
        return dept;
    }
   
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
         help(root, 0);
        vector<int> res;
        for (int q : queries)
        {
            int lv = mp[q].first;

            int max_dept = mp[q].second;

            if (max_dept == d1[lv])                          // condition if current node has maximum length then take second max length
                res.push_back(lv + d2[lv]-1);
            else
                res.push_back(lv + d1[lv]-1);               //  if current node is not the max node then take first max

        }

        return res;
    }
};
