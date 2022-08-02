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
    ListNode* middleNode(ListNode* head) {
        
        
        int count =0;
        
        ListNode * t = head;
        while(t!=NULL)
        {
            count++;
            t=t->next;
        }
        
        count  = count%2==0 ? count/2 : count/2;
        
       
        while(count >0  )
        {
            count--;
            head = head-> next;
        }
        
        return head;
    }
};
