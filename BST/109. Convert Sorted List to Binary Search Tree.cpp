/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
/**
 * Definition for aa binary tree node.
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

    TreeNode* help(vector<int>&v ,int min , int max )
    {
        if(min > max) return NULL;
        if(min == max )
        {
            return new TreeNode(v[min]);
        }

        int mid = (min+max)>>1;

        TreeNode *root= new TreeNode(v[mid]);
        root->left = help(v,min,mid-1);
        root->right = help(v,mid+1, max);

        return root;

    }

    TreeNode* sortedListToBST(ListNode* head) {

        vector<int> v;

        while(head != NULL)
        {
            v.push_back(head->val);
            head=head->next;
        }
        TreeNode *ans = help(v,0,v.size()-1);
        return ans;
    }
};
