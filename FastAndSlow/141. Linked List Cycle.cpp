 /*Return true if there is a cycle in the linked list. Otherwise, return false.*/
class Solution {
public:
    bool hasCycle(ListNode *head) {
        
        
        if(   head == NULL or head->next ==  NULL or head->next->next == NULL) return false;
        
        ListNode *slow = head , *fast= head->next->next;
        
        while(slow != fast)
        {
            cout<<"\tslow  "<<slow->val;
            slow = slow->next;
            
         
            cout<<"\tfast  "<<fast->val<<endl;
            
            if(fast->next == NULL or fast->next->next == NULL) return false;
            fast = fast->next->next;
            
        }
        
        
        if(slow == NULL  or fast == NULL)
            return false;
        
        return true;
    }
};
