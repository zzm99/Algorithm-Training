class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 0) return 0;
        vector<int> dp(prices.size());
        int curmin = prices[0];
        dp[0] = 0;
        for(int i=1; i<prices.size(); i++){
            dp[i] = max(dp[i-1], prices[i]-curmin);
            curmin = min(curmin,prices[i]);
        }
        return dp[prices.size()-1];
    }
};