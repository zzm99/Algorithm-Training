class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for(int i = 0; i < n; i++) {
            dp[i][i] = piles[i]; //初始化只有i一个石头堆的情形
        }
        for(int dis = 1; dis < n; dis++) {//依次计算相邻2个石头堆到n个石头堆的情形
            for(int i = 0; i < n - dis; i++) {
                dp[i][i+dis] = max(piles[i]-dp[i+1][i+dis], piles[i+dis]-dp[i][i+dis-1]);
            }
        }
        return dp[0][n-1] > 0;
    }
};