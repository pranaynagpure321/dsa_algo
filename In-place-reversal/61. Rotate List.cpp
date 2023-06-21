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
    ListNode* rotateRight(ListNode* head, int k) {
      int len =0;
      ListNode *tmp = head;
      while(tmp != NULL)
      {
        len++;
        tmp=tmp->next;
      }
      if( len==0 || k%len == 0 || k==0 ) return head;
      int kth_node = len - k%len;

     
      ListNode *hold= NULL;
      tmp = head;

      while(kth_node>1)
      {
        kth_node--;
        tmp=tmp->next;
      }

      hold = tmp->next;
      tmp->next = NULL;
      tmp = hold;

      while(tmp!= NULL and tmp->next != NULL)
      tmp=tmp->next;

      tmp->next = head;
      return hold;  
    }
};
