/*
23. Merge k Sorted Lists
Hard

Add to List

Share
You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

Merge all the linked-lists into one sorted linked-list and return it.
Example 1:

Input: lists = [[1,4,5],[1,3,4],[2,6]]
Output: [1,1,2,3,4,4,5,6]
Explanation: The linked-lists are:
[
  1->4->5,
  1->3->4,
  2->6
]
merging them into one sorted list:
1->1->2->3->4->4->5->6
Example 2:

Input: lists = []
Output: []
Example 3:

Input: lists = [[]]
Output: []
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
 struct CompareVal {
    bool operator()(ListNode * p1,ListNode *  p2)
    {
        //for ascending order of node values
        return p1->val > p2->val;
    }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
       
    priority_queue<ListNode * ,vector<ListNode *>, CompareVal > pq;

    for(ListNode * head : lists)
    {
        if(head!= NULL)
        pq.push(head);
    }
    
    ListNode *head = NULL, *cur = NULL;
    while(pq.size() >0 )                                            //merge list based on priority
    {
        ListNode * tmp = pq.top();
        pq.pop();
        
        if(head == NULL) {
            head = tmp; cur = tmp;

            tmp = tmp->next;
            if(tmp!= NULL)
            pq.push(tmp);      
            
        }

        else{

            cur->next = tmp;
            cur= cur->next;
            tmp = tmp->next;
              if(tmp!= NULL)
            pq.push(tmp);      

        }
    }
        //time nlogk  k no of  list 
        //space k
        
    return head;
        
    }
};
