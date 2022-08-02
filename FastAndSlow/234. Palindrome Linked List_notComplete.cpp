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
class Solution {
public:
    string getStringFront(ListNode* head)
    {
        string s ="";
        ListNode *t = head;
        while(t != NULL)
        {
            s+= to_string( t->val);
            t= t->next;
        }
        return s;
    }
    
    string getStringInreverse(ListNode *head, string s)
    {
        if(head-> next != NULL) 
        {
            s= getStringInreverse(head->next, s);
        }
        
        s +=  to_string(head->val);
       // cout<<s<<endl;
        return s;
    }
    
    bool isPalindrome(ListNode* head) {
        
        
        string s1 =getStringFront(head);
        string s2 = getStringInreverse(head, "");
        
        return s1==s2;
    }
};
