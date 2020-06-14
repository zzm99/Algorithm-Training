class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty()) return 0;
        vector<vector<int>> dp(prices.size(), vector<int>(3));
        dp[0][0] = 0;
        dp[0][1] = -prices[0];
        dp[0][2] = 0;
        for(int i=1; i<prices.size(); i++){
            dp[i][0] = max(dp[i-1][0], dp[i-1][2]); // 当前未持有股票 （包括了冷冻期的情况了）
            dp[i][1] = max(dp[i-1][1], dp[i-1][0]-prices[i]); // 当前持有股票
            dp[i][2] = dp[i-1][1]+prices[i]; // 下一个i为冷冻期
        }
        return max(dp[prices.size()-1][0], dp[prices.size()-1][2]);
    }
};