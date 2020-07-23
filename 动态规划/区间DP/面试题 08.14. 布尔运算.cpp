class Solution {
public:
    int countEval(string s, int result) {
        int dp[25][25][2] = {0};
        char sign[25];
        vector<int> nums;
        for(int i=0; i<s.size(); i++) {
            if(i % 2 == 0) nums.push_back(s[i]-'0');
            else sign[i >> 1] = s[i];
        }
        for(int i=0; i<nums.size(); i++) dp[i][i][nums[i]] = 1;
        for(int len = 2; len <= nums.size(); len ++) {
            for(int i=0; i+len-1 < nums.size(); i++) {
                int j = i+len-1;
                for(int k=i; k<j; k++) {
                    if(sign[k] == '^') {
                        dp[i][j][1] += dp[i][k][0]*dp[k+1][j][1] + dp[i][k][1]*dp[k+1][j][0];
                        dp[i][j][0] += dp[i][k][1]*dp[k+1][j][1] + dp[i][k][0]*dp[k+1][j][0];
                    } else if(sign[k] == '&') {
                        dp[i][j][1] += dp[i][k][1]*dp[k+1][j][1];
                        dp[i][j][0] += dp[i][k][0]*dp[k+1][j][1] + dp[i][k][0]*dp[k+1][j][0] + dp[i][k][1]*dp[k+1][j][0];
                    } else {
                        dp[i][j][1] += dp[i][k][0]*dp[k+1][j][1] + dp[i][k][1]*dp[k+1][j][1] + dp[i][k][1]*dp[k+1][j][0];
                        dp[i][j][0] += dp[i][k][0]*dp[k+1][j][0];
                    }
                }
            }
        }
        return dp[0][nums.size()-1][result];
    }
};