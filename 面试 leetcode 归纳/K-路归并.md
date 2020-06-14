# K-路归并

1. 把每个数组中的第一个元素都加入最小堆中
2. 取出堆顶元素（全局最小），将该元素放入排好序的结果集合里面
3. 将刚取出的元素所在的数组里面的下一个元素加入堆
4. 重复步骤2，3，直到处理完所有数字

识别K路归并：

- 该问题的输入是排好序的数组，链表或是矩阵
- 如果问题让咱们合并多个排好序的集合，或是需要找这些集合中最小的元素

```cpp
// 23. 合并K个排序链表
// 合并 k 个排序链表，返回合并后的排序链表。请分析和描述算法的复杂度。
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

/////////////////

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
```

```cpp
// 373. 查找和最小的K对数字
// 给定两个以升序排列的整形数组 nums1 和 nums2, 以及一个整数 k。

// 定义一对值 (u,v)，其中第一个元素来自 nums1，第二个元素来自 nums2。

// 找到和最小的 k 对数字 (u1,v1), (u2,v2) ... (uk,vk)。
class Solution {
public:
    typedef pair<int,int> PII;
    class cmp{
    public:
        bool operator()(PII & x, PII & y){
            return x.first+x.second < y.first+y.second;
        }
    };
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<PII,vector<PII>,cmp> q;
        for(auto & s: nums1){
            for(auto & t : nums2){
                q.push({s,t});
                if(q.size() > k) {
                    q.pop();
                    if(!q.empty() && q.top().first + q.top().second <= s+t)break;
                }
            }
            if(q.size() == k && s + nums2[0] >= q.top().first + q.top().second) break;
        }
        vector<vector<int>> res;
        while(!q.empty()){
            res.push_back({q.top().first,q.top().second});
            q.pop();
        }
        return res;
    }
};
```