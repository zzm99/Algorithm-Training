class Solution {
public:
    int strangePrinter(string s) {
        int n = s.size();
        if(n == 0) return 0;
        vector<vector<int>> dp(n, vector<int>(n));
        for(int i=0; i<n; i++) dp[i][i] = 1;
        for(int i=n-1; i>=0; i--) {
            for(int j=i+1; j<n; j++) {
                dp[i][j] = 1 + dp[i+1][j];
                for(int k=i+1; k<j; k++) {
                    if(s[i] == s[k]) {
                        dp[i][j] = min(dp[i][j], dp[i+1][k]+dp[k+1][j]);
                    }
                }
                if(s[i] == s[j]) dp[i][j] = min(dp[i][j], dp[i+1][j]);
            }
        }
        return dp[0][n-1];
    }
};