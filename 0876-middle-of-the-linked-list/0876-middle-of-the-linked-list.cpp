class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* fptr = head; // fastpointer
        ListNode* sptr = head;//slowpointer
        while(fptr != NULL && fptr->next!=NULL){
            fptr = fptr->next->next;
            sptr = sptr->next;
        }
        return sptr;
    }
};