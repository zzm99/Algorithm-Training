class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<int> delta(limit * 2 + 2);
        for (int i = 0; i < n / 2; ++i) {
            int lo = 1 + min(nums[i], nums[n - i - 1]);
            int hi = limit + max(nums[i], nums[n - i - 1]);
            int sum = nums[i] + nums[n - i - 1];
            delta[lo]--;
            delta[sum]--;
            delta[sum + 1]++;
            delta[hi + 1]++;
        }
        int now = n;
        int ans = n;
        for (int i = 2; i <= limit * 2; ++i) {
            now += delta[i];
            ans = min(ans, now);
        }
        return ans;
    }
};
