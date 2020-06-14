class Solution {
public:
    int maxProfit(int z, vector<int>& prices) {
        int n = prices.size();
        if(n == 0 || n == 1) return 0;
        if(z >= n) return greedy(prices);
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(z+1, vector<int>(2, 0)));
        for(int i=1; i<=z; i++) dp[0][i][1] = -1e8;
        for(int i=1; i<=n; i++) {
            for(int k=1; k<=z; k++) {
                dp[i][k][0] = max(dp[i-1][k][1]+prices[i-1], dp[i-1][k][0]);
                dp[i][k][1] = max(dp[i-1][k-1][0]-prices[i-1], dp[i-1][k][1]);
            }
        }
        int res = 0;
        for(int i=1; i<=z; i++) res = max(res, dp[n][i][0]);
        return res;
    }
    int greedy(vector<int>& prices) {
        int max = 0;
        for(int i=1; i<prices.size(); i++) {
            if(prices[i] > prices[i-1]) max+=prices[i]-prices[i-1];
        }
        return max;
    }
};