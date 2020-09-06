class Solution {
public:
    // 结束位置和总共消耗燃料
    int dp[105][205];
    int mod = 1e9+7;
    int countRoutes(vector<int>& l, int s, int e, int fuel) {
        int n = l.size();
        dp[s][0] = 1;
        int ans = 0;
        for (int f = 0; f <= fuel; ++f) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (i == j) continue;
                    int diff = abs(l[i]-l[j]);
                    if (f + diff <= 200) {
                        dp[j][f+diff] += dp[i][f];
                        dp[j][f+diff] %= mod;
                    }
                }
            }
            ans += dp[e][f];
            ans %= mod;
        }
        return ans;
    }
};
