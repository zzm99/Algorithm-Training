class Solution {
public:
    bool isMatch(string s, string p) {
        if(p.empty()) return s.empty();
        auto f = !s.empty() && (s[0] == p[0] || p[0] == '.');
        if(p.size() >= 2 && p[1] == '*')
            return isMatch(s, p.substr(2)) || (f && isMatch(s.substr(1), p));
        else
            return f && isMatch(s.substr(1), p.substr(1));
    }
};

////

class Solution {
public:
    bool isMatch(string s, string p) {
        int slen = s.size(), plen = p.size();
        if(slen == 0 && plen == 0) return true;
        vector<vector<bool>> dp(slen+1, vector<bool>(plen+1));
        dp[0][0] = true;
        // 初始化s=0的情况
        for(int j=1; j<=plen; j++) {
            if(j == 1) dp[0][j] = false;
            if(p[j-1] == '*' && dp[0][j-2]) dp[0][j] = true;
        }
        for(int i=1; i<=slen; i++) {
            for(int j=1; j<=plen; j++) {
                if(s[i-1] == p[j-1] || p[j-1] == '.') {
                    dp[i][j] = dp[i-1][j-1];
                } else if(p[j-1] == '*') {
                    if(j < 2) dp[i][j] = false;
                    if(p[j-2] == s[i-1] || p[j-2] == '.') {
                        dp[i][j] = dp[i-1][j] || dp[i][j-1] || dp[i][j-2];
                    } else if(p[j-2] != s[i-1] && p[j-2] != '.') {
                        dp[i][j] = dp[i][j-2];
                    }
                } else {
                    dp[i][j] = false;
                }
            }
        }
        return dp[slen][plen];
    }
};