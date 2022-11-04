/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
     ListNode merge(ListNode l1, ListNode l2)
    {
        ListNode   head =new ListNode(0)  , curr = head;

        while (l1 != null &&  l2!= null)
        {
            if(l1.val <= l2.val)
            {
                curr.next = l1;
                l1 = l1.next;
            }
            else
            {
                curr.next = l2;
                l2= l2.next;
            }
            curr = curr.next;
        }

        if (l1 != null)
        {
            curr.next = l1;
            //l1 =l1.next;
        }
        if (l2 != null)
        {
            curr.next = l2;
            //l2=l2.next;
        }

        return  head.next;
    }
    public ListNode sortList(ListNode head) {
        
        if(head == null || (head.next == null)) return  head;
        ListNode tmp = null;
        ListNode slow = head;
        ListNode fast = head;
        
      //using fast and slow to find middle element
        while (fast != null && fast.next!= null)
        {
            tmp = slow;
            slow = slow.next;
            fast = fast.next.next;
        }

        tmp.next =null;

        ListNode l1 = sortList(head);
        ListNode l2 = sortList(slow);

        return merge(l1,l2);
    }
}
