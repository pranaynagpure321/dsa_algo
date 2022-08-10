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

/*92. Reverse Linked List II
Medium

7665

334

Add to List

Share
Given the head of a singly linked list and two integers left and right where left <= right, reverse the nodes of the list from position left to position right, and return the reversed list.
Example 1:


Input: head = [1,2,3,4,5], left = 2, right = 4
Output: [1,4,3,2,5] */
class Solution {
public:
     
    ListNode* reverse(ListNode* head) {
          ListNode *prev=NULL, *curr = NULL, *temp = head;
        
        while(temp != NULL)
        {
            curr  =  temp;
            temp = temp->next;
            curr->next = prev;
            prev = curr;
        }
        
        return prev;
        
    }
    
    
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        
        ListNode *h1 = head;
        
        
        if(left == 1)
        {
            int count =1;
            ListNode *h2 = h1;
            while(count < right )
            {
                count++;
                h2 = h2 ->next;
            }
            
            ListNode *temp = h2->next; h2->next=NULL;
            ListNode *newHead = reverse(h1) , *temp2 = newHead ;
            
            while(temp2->next != NULL) temp2 = temp2->next;
            
            temp2->next = temp;
            
            return newHead;
        }
        else
        {
            int count =1;
            ListNode *tail1 = h1 , *head2 = NULL;
            
            while(count+1 < left)
            {
                count++;
                tail1 = tail1->next;
            }
            
            head2 = tail1->next; tail1->next = NULL;
            
            ListNode *tmp = head2;
            
            //check if its goes to end
            count =1;
            
            while(count < right - left + 1) { count++; tmp=tmp->next;}
            
            if(tmp->next == NULL)
            {
                ListNode *prev = reverse(head2);
                tail1->next  = prev;
                return h1;
            }
            
            ListNode *head3 = tmp->next; tmp->next=NULL;
            ListNode *prev = reverse(head2);
            tail1->next  = prev;
            
            tmp = prev;
            
            while(tmp->next!= NULL) tmp= tmp->next;
            
            tmp->next = head3;
            
            return h1;
            
        }
    }
};
