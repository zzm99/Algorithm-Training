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
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        if(lists.size() == 0) return NULL;
        ListNode* p = lists[0];
        for(int i=1; i<lists.size(); i++) {
            p = mergeTwoLists(p, lists[i]);
        }
        return p;
    }
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;
        ListNode dummy(-1);
        ListNode *p = &dummy;
        while(l1 && l2) {
            if(l1->val > l2->val) {
                p->next = l2;
                l2 = l2->next;
            } else {
                p->next = l1;
                l1 = l1->next;
            }
            p = p->next;
        }
        p->next = l1 != NULL ? l1 : l2;
        return dummy.next;
    }
};

////


class Solution {
public:
    // 小根堆的回调函数
    struct cmp{  
       bool operator()(ListNode *a,ListNode *b){
          return a->val > b->val;
       }
    };
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, cmp> pri_queue;
        // 建立大小为k的小根堆
        for(auto elem : lists){
            if(elem) pri_queue.push(elem);
        }
        // 可以使用哑节点/哨兵节点
        ListNode dummy(-1);
        ListNode* p = &dummy;
        // 开始出队
        while(!pri_queue.empty()){
            ListNode* top = pri_queue.top(); pri_queue.pop();
            p->next = top; p = top;
            if(top->next) pri_queue.push(top->next);
        }
        return dummy.next;  
    }
};


/// 

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