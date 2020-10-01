class Solution {
public:
    ListNode* sortInList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode* pre = new ListNode(-1);
        pre->next = new ListNode(head->val);
        while(head->next != NULL) {
            ListNode* next = head->next;
            ListNode* t = pre;
            bool flag = true;
            while(t->next != NULL) {
                ListNode* p = t->next;
                if(next->val < p->val) {
                    ListNode* nt = new ListNode(next->val);
                    t->next = nt;
                    nt->next = p;
                    flag = false;
                    break;
                }
                t = t->next;
            }
            if(flag) {
                t->next = new ListNode(next->val);
            }
            head = head->next;
        }
        return pre->next;
    }
};