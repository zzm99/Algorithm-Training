class Solution {
public:
    int minimumDeviation(vector<int>& a) {
        int n = a.size(), mi = INT_MAX, res = INT_MAX;
        priority_queue<int> q;
        for (int i = 0; i < n; i++) {
            if (a[i] & 1) a[i] *= 2;  // 如果是奇数，那么能变成的最大偶数为a[i] * 2
            q.push(a[i]);
            mi = min(mi, a[i]);
        }
        while (1) {
            int tt = q.top();        // 取出当前最大数
            q.pop();
            res = min(res, tt - mi); // 维护答案
            if (tt & 1) break;       // 奇数不能再除以2，最大值不可能再改变，差距也就不会再被缩小，退出循环
            mi = min(mi, tt >> 1);   // 维护当前堆的最小值
            q.push(tt >> 1);         // 除2后重新加入堆
        }
        return res;
    }
};
