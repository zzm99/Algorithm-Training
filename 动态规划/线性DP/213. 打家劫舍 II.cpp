class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        if(nums.size() == 1) return nums[0]; 
        vector<int> a = nums; a.pop_back();
        vector<int> b = nums; b.erase(b.begin());
        return max(help(a), help(b));
    }
    int help(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        if(nums.size() == 1) return nums[0]; 
        vector<int> dp = nums;
        dp[1] = max(nums[0], nums[1]);
        int ans = max(dp[0], dp[1]);
        for(int i=2; i<nums.size(); i++){
            dp[i] = max(dp[i-1], dp[i-2]+nums[i]);
            ans = max(dp[i], ans);
        }
        return ans;
    }
};