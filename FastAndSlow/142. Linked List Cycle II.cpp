/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/*Given the head of a linked list, return the node where the cycle begins. If there is no cycle, return null.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to (0-indexed). It is -1 if there is no cycle. Note that pos is not passed as a parameter.

Do not modify the linked list.

 

Example 1:


Input: head = [3,2,0,-4], pos = 1
Output: tail connects to node index 1
Explanation: There is a cycle in the linked list, where tail connects to the second node. */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        
        
        if(head == NULL or head->next == NULL or  head->next->next == NULL) return NULL;
        
        ListNode *tortoise = head, *hare = head  ;
        
        
        while(tortoise != NULL and hare!= NULL )
        {
            tortoise= tortoise ->next;
            
            if(hare==NULL or hare-> next == NULL or hare->next->next == NULL) return NULL;
           
            hare = hare ->next->next;
            
            if(tortoise == hare)  //find first intersection from start
                break;
        }
        
        
        ListNode *ptr1 = head , *ptr2 = tortoise; //find second intersection by taking on pointer to first intersection and from start
        
        while(ptr1 != ptr2)
        {
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        
      
        return ptr1;
        
    }
};
