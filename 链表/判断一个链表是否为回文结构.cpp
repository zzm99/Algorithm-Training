/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 * };
 */

class Solution {
public:
    bool isPail(ListNode* head) {
        if(!head || !head->next) return true;
        ListNode *slow = head, *fast = head;
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *head1 = slow;
        if(fast) head1 = slow->next;
        head1 = reverseList(head1);
        slow = head;
        fast = head1;
        while(fast) {
            if(slow->val != fast->val) return false;
            slow = slow->next;
            fast = fast->next;
        }
        return true;
    }
    ListNode* reverseList(ListNode* head) {
        ListNode *pre = NULL, *cur = head, *cur_next = NULL;
        while(cur) {
            cur_next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = cur_next;
        }
        return pre;
    }
};