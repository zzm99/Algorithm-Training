class Solution {
public:
    int maxCoins(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        vector<vector<int>> dp(nums.size(), vector<int>(nums.size()));
        for(int r=2; r<nums.size(); r++){
            for(int i=0; i<nums.size()-r; i++){
                int j = i+r;
                for(int k=i+1; k<j; k++){
                    dp[i][j] = max(dp[i][j],dp[i][k]+dp[k][j]+nums[i]*nums[k]*nums[j]);
                }
            }
        }
        return dp[0][nums.size()-1];
    }
};