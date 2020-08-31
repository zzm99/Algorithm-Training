// p_dp[i] 以 i 结尾的乘积为正数的最长子数组长度
// n_dp[i] 以 i 结尾的乘积为负数的最长子数组长度

class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int size = nums.size();
        
        vector<int> p_dp(size);
        vector<int> n_dp(size);
        
        p_dp[0] = nums[0] > 0 ? 1 : 0;
        n_dp[0] = nums[0] < 0 ? 1 : 0;      
        
        int result = p_dp[0];
        
        for (int i = 1; i < size; i++) {
            if (nums[i] > 0) {
                p_dp[i] = p_dp[i - 1] + 1;
                n_dp[i] = n_dp[i - 1] > 0 ? n_dp[i - 1] + 1 : 0;
            } else if (nums[i] < 0) {
                p_dp[i] = n_dp[i - 1] > 0 ? n_dp[i - 1] + 1 : 0;
                n_dp[i] = p_dp[i - 1] + 1;
            } else {
                p_dp[i] = 0;
                n_dp[i] = 0;
            }
            
            result = max(result, p_dp[i]);
        }
        
        return result;
    }
};