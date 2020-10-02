/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 * };
 */

class Solution {
public:
    /**
     * 
     * @param head ListNode类 
     * @param m int整型 
     * @param n int整型 
     * @return ListNode类
     */
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        // write code here
        ListNode *pre, *post;
        ListNode *begin, *end;
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *p = dummy;
        int cnt = 0;
        while(cnt <= n) {
            if(cnt+1 == m) {
                pre = p;
                begin = p->next;
            }
            if(cnt == n) {
                end = p;
                post = p->next;
            }
            cnt++;
            p = p->next;
        }
        ListNode *q = begin;
        p = begin->next;
        while(p != post) {
            ListNode *tmp = p->next;
            p->next = q;
            q = p;
            p = tmp;
        }
        pre->next = end;
        begin->next = post;
        return dummy->next;
    }
};