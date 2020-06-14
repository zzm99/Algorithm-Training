class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        if(n == 0 || n == 1) return n;
        vector<vector<int>> dp(n, vector<int>(n));
        for(int i=0; i<n; i++) dp[i][i] = 1;
        for(int i=n-1; i>=0; i--) {
            for(int j=i+1; j<n; j++) {
                if(s[i] == s[j]) {
                    dp[i][j] = 2 + dp[i+1][j-1];
                } else {
                    dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
                }
            }
        }
        return dp[0][n-1];
    }
};