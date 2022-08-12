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
    ListNode* reverse(ListNode* head, int i , int  j)  {
       
         
        ListNode *prev=NULL, *curr = NULL, *temp = head;
        
        while(temp != NULL)
        {
            curr  =  temp;
            temp = temp->next;
            curr->next = prev;
            prev = curr;
        }
        
        //hold->next= h2;
        
        return prev;
        
    }
    
    int getLength(ListNode *head)
    {
        int ans=0;
        
        ListNode *tmp= head;
        while(tmp!=NULL) { ans++; tmp=tmp->next; }
        
        return ans;
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        int len = getLength(head);
        
        
        ListNode *h1 = head , *end1 = NULL; 
        
        for(int i =1 ;i<= len ; i+=k)
        {
            
            if(i+k-1 <= len)
            head = reverseBetween(head, i, i+k-1);
            
        }
        
        
        
        return head;
        
        
    }
};
