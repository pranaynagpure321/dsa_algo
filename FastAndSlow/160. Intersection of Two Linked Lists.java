/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    int getLength(ListNode a)
    {
        int i =0;

        ListNode tmp = a;

        while(tmp!= null) { tmp=tmp.next; i++;}

        return i;
    }

    ListNode getCommanNode(ListNode headA, ListNode headB)
    {
        if(headA == headB ) return headA;
        ListNode l1 = headA , l2= headB, tmp= null; 
        while(l1.next!=l2.next)
        {
            l1 = l1.next; l2=l2.next;
        }
        if(  l1!= null && l1.next!= null && l1.next == l2.next ) tmp = l1.next;

        return tmp;
    }

    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {

      
        int a = getLength(headA);
        int b = getLength(headB);
        ListNode tmp = null;

        if(a==b) return getCommanNode(headA,headB); 
        if(a>b)
        {
            tmp =headA;
            int j = a-b;
            while(j>0)
              {tmp = tmp.next; j--;}
            
            return getCommanNode(tmp,headB);
        }
        else if(a<b) {
            
            tmp =headB;
            int j = b-a;
            while(j>0)
            {tmp = tmp.next; j--;}
            return getCommanNode(headA,tmp);
        }

        return null;
    }
  
  
  //optimized(small code) solution cpp 
  /**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
         ListNode *ptrA = headA, *ptrB = headB;
        while (ptrA != ptrB) { // loop until we found the first common node
            ptrA = ptrA == NULL ? headB : ptrA->next; // once we're done with A, move to B
            ptrB = ptrB == NULL ? headA : ptrB->next; // once we're done with B, move to A
        }
	 return ptrA;
    }
};
}
