class Solution {
public:
    void reorderList(ListNode* head) {
        if(head == NULL || head->next == NULL || head->next->next == NULL) return;
        ListNode *first = head, *low = head;
        while(first && first->next && first->next->next) {
            low = low->next;
            first = first->next->next;
        }
        ListNode *p2 = low->next;
        low->next = NULL;
        ListNode* pre = NULL, *cur = p2;
        while(cur) {
            ListNode* tmp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tmp;
        }     
        p2 = pre;  
        ListNode* p1 = head;
        
        while(p1 && p2) {
            ListNode* tmp1 = p1->next;
            ListNode* tmp2 = p2->next;
            p1->next = p2;
            p2->next = tmp1;
            p2 = tmp2;
            p1 = p1->next->next;
        }
    }
};