/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* pre;
        while(head && head->next){
            if(head->val <= head->next->val){
                head = head->next;
                continue;
            }
            pre = dummy;
            while(pre->next->val < head->next->val) pre = pre->next;
            ListNode* curr = head->next;
            head->next = curr->next;
            curr->next = pre->next;
            pre->next = curr;
        }
        return dummy->next;
    }
};