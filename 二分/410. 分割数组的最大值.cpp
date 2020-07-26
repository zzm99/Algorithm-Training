class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        long long left = 0;
        long long right = 0;
        for(auto& x: nums) {
            left = max(left, (long long)x);
            right += x;
        }
        while(left < right) {
            int cnt = 0;
            long long mid = (left + right) >> 1;
            long long sum = 0;
            for(auto x : nums) {
                if(sum + x > mid) {
                    sum = 0;
                    cnt++;
                }
                sum += x;
            }
            cnt++; // the last one
            if(cnt > m) left = mid + 1;
            else right = mid;
        }
        return left;
    }
};