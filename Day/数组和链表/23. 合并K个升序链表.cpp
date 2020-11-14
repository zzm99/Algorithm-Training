/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    struct cmp {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, cmp> p_q;
        for(auto l: lists) {
            if(l) {
                p_q.push(l);
            }
        }
        ListNode* dummy = new ListNode(-1);
        ListNode* p = dummy;
        while(!p_q.empty()) {
            ListNode* front = p_q.top();
            p_q.pop();
            p->next = front;
            p = p->next;
            if(front->next) {
                p_q.push(front->next);
            }
        }
        return dummy->next;
    }
};


//////


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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0) return NULL;
        if(lists.size() == 1) return lists[0];
        if(lists.size() == 2) return mergeTwoLists(lists[0], lists[1]);

        int mid = lists.size()/2;
        vector<ListNode*> l1(mid);
        for(int i=0; i<mid; i++) l1[i] = lists[i];
        vector<ListNode*> l2(lists.size()-mid);
        for(int i=0; i<lists.size()-mid; i++) l2[i] = lists[mid+i];
        return mergeTwoLists(mergeKLists(l1), mergeKLists(l2)); 
    }
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2){
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;
        ListNode* head = NULL;
        if(l1->val <= l2->val){
            head = l1;
            head->next = mergeTwoLists(l1->next, l2);
        }else{
            head = l2;
            head->next = mergeTwoLists(l1, l2->next);
        }
        return head;
    }
};