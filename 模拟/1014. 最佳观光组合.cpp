class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& A) {
        int ans = 0, mx = A[0] + 0;
        for (int j = 1; j < A.size(); ++j) {
            ans = max(ans, mx + A[j] - j);
            // 边遍历边维护
            mx = max(mx, A[j] + j);
        }
        return ans;
    }
};

///

class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& A) {
        vector<int> l = A;
        vector<int> r = A;
        int cur = INT_MIN;
        for(int i=0; i<l.size(); i++) {
            cur = max(cur, l[i]+i);
            l[i] = cur;
        }
        cur = INT_MIN;
        for(int i=r.size()-1; i>=0; i--) {
            cur = max(cur, A[i]-i);
            r[i] = cur;
        }
        cur = INT_MIN;
        for(int i=0; i<l.size()-1; i++) {
            cur = max(cur, l[i] + r[i+1]);
        }
        return cur;
    }
};