class Solution {
public:
    void printLinkedListInReverse(ImmutableListNode* head) {
        
        
       
         if(head->getNext() != NULL)
         printLinkedListInReverse(head->getNext());
         head->printValue();
            
        
        
       return;
    }
};
