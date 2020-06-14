class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum % 2) return false;
        vector<int> dp(sum/2+1);
        dp[0] = 1;
        for(int i=0; i<nums.size(); i++){
            for(int j=sum/2; j>=nums[i]; --j){
                dp[j] |= dp[j-nums[i]];
            }
            if(dp[sum/2]) return true;
        }
        return false;
    }
};