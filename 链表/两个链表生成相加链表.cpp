class Solution {
public:
    ListNode* addInList(ListNode* head1, ListNode* head2) {
        stack<int> st1;
        stack<int> st2;
        while(head1 || head2) {
            if(head1) {
                st1.push(head1->val);
                head1 = head1->next;
            }
            if(head2) {
                st2.push(head2->val);
                head2 = head2->next;
            }
        }
        ListNode *vhead = new ListNode(-1);
        int carry = 0;
        while(!st1.empty() || !st2.empty() || carry != 0) {
            int a = 0, b = 0;
            if(!st1.empty()) {
                a = st1.top();
                st1.pop();
            }
            if(!st2.empty()) {
                b = st2.top();
                st2.pop();
            }
            int get_sum = a + b + carry;
            int ans = get_sum % 10;
            carry = get_sum / 10;
            ListNode *cur = new ListNode(ans);
            cur->next = vhead->next;
            vhead->next = cur;
        }
        return vhead->next;
    }
};