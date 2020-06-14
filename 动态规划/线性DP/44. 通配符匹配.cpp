class Solution {
public:
    bool isMatch(string s, string p) {
        int slen = s.size(), plen = p.size();
        vector<vector<bool>> dp(plen+1, vector<bool>(slen+1));
        dp[0][0] = true;
        for(int i=1; i<=slen; i++) dp[0][i] = false;
        for(int i=1; i<=plen; i++) {
            if(p[i-1] == '*') {
                dp[i][0] = dp[i-1][0];
                for(int j=1; j<=slen; j++) {
                    dp[i][j] = (dp[i][j-1] || dp[i-1][j]);
                }
            } else if(p[i-1] == '?') {
                dp[i][0] = false;
                for(int j=1; j<=slen; j++) {
                    dp[i][j] = dp[i-1][j-1];
                }
            } else {
                dp[i][0] = false;
                for(int j=1; j<=slen; j++) {
                    dp[i][j] = (s[j-1] == p[i-1] && dp[i-1][j-1]);
                }
            }
        }
        return dp[plen][slen];
    }
};