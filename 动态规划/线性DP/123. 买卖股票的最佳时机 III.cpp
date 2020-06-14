class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n == 0 || n == 1) return 0;
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(3, vector<int>(2, 0)));
        dp[0][2][1] = dp[0][1][1] = -1e8;
        for(int i=1; i<=n; i++) {
            for(int k=1; k<=2; k++) {
                dp[i][k][0] = max(dp[i-1][k][1]+prices[i-1], dp[i-1][k][0]);
                dp[i][k][1] = max(dp[i-1][k-1][0]-prices[i-1], dp[i-1][k][1]);
            }
        }
        return max(dp[n][1][0], dp[n][2][0]);
    }
};