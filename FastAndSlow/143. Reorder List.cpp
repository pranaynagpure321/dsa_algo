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


/*143. Reorder List
Medium

6697

232

Add to List

Share
You are given the head of a singly linked-list. The list can be represented as:

L0 → L1 → … → Ln - 1 → Ln
Reorder the list to be on the following form:

L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
You may not modify the values in the list's nodes. Only nodes themselves may be changed.*/

/* solution
   1 reverser second half
   2 merge the linked list
*/
class Solution {

    
    ListNode* ReverseSecondHalf(ListNode * head)
    {
        ListNode *ptr = head;
        int count =0;
        while(ptr != NULL)
        {
            ptr = ptr -> next;
            count++;
        }
        
        ListNode *head2 = NULL; ptr = head;
        
        if(count %2 == 0)
        {
           count = count/2 - 1;
            
            
            while(count > 0 )
            {
                ptr = ptr -> next;
                count--;
            }
            
            head2 = ptr -> next;
            ptr->next = NULL;
        }
        
        else
        {
           count = count/2;
            
            while(count  > 0 )
            {
                ptr = ptr -> next;
                count--;
            }
            head2 = ptr -> next;
            ptr->next = NULL;
        }
        
        ListNode *curr = head2, *prev= NULL;
        
        while(head2 != NULL)
        {
            
            head2 = curr -> next;
            curr -> next = prev ;
            prev = curr;
            curr = head2;
        }
        
        return prev;
        
    }
    
public:
    void reorderList(ListNode* head) {
        
        
        ListNode *head2 = ReverseSecondHalf(head) ;
        
        ListNode *curr1 = head, *curr2 = head2;
        
        
         while(head2 != NULL)
         {
             head = curr1 -> next;
             head2 = curr2 -> next;
             curr1 -> next = curr2;
             curr2->next = head;
             curr1 = head;
             curr2 = head2;
         }
        
        
    }
};
