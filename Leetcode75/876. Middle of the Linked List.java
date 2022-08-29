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
    
    int count  =0;
    int mid =0;
    public ListNode middleNode(ListNode head) {
        
        if(head == null) { 
          
            mid = (count)/2 + 1;
            return null;
        }
        
        
        count++;
        ListNode ans =  middleNode(head.next);
        count--;
        
        if(count+1  == mid)
        {
            ans = head;
            return ans;
        }
        
        
        return ans;
        
    }
}
