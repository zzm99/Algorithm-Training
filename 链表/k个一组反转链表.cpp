/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 * };
 */

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k < 2) return head;
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *prev = dummy;
        ListNode *curr = head;
        int len = 0;
        while(head) {
            head = head->next;
            len++;
        }
        for(int i=0; i<len/k; i++) {
            for(int j=0; j<k-1; j++) {
                ListNode *tmp = curr->next;
                curr->next = tmp->next;
                tmp->next = prev->next;
                prev->next = tmp;
            }
            prev = curr;
            curr = prev->next;
        }
        return dummy->next;
    }
};