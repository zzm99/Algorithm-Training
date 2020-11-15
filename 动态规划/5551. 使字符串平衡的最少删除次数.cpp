class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(2));
        dp[0][0] = s[0] == 'a' ? 0 : 1;
        dp[0][1] = s[0] == 'b' ? 0 : 1;
        for(int i=1; i<n; i++) {
            if(s[i] == 'a') {
                dp[i][0] = dp[i-1][0];
                dp[i][1] = min(dp[i-1][0], dp[i-1][1])+1;
            } else {
                dp[i][0] = dp[i-1][0]+1;
                dp[i][1] = min(dp[i-1][0], dp[i-1][1]);
            }
        }
        return min(dp[n-1][0], dp[n-1][1]);
    }
};