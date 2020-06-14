class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> dp = triangle;
        for(int i=1; i<dp.size(); i++){
            for(int j=0; j<dp[i].size(); j++){
                if(j == 0) dp[i][j] += dp[i-1][j];
                else if(j == dp[i].size()-1) dp[i][j] += dp[i-1][j-1];
                else  dp[i][j] += min(dp[i-1][j-1], dp[i-1][j]);
            }
        }
        int mina = INT_MAX;
        for(int i=0; i<dp[dp.size()-1].size(); i++)
            mina = min(mina, dp[dp.size()-1][i]);
        return mina;
    }
};

///

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int len = triangle.size();
        if(len == 0) return 0;
        int dp[len+1];
        for(int i=0; i<len+1; i++) dp[i] = 0;
        dp[0] = triangle[0][0];
        for(int i=1; i<len; i++) {
            int n = triangle[i].size();
            for(int j=n-1; j>=0; j--) {
                if(j == 0) dp[j] += triangle[i][j];
                else if(j == n-1) dp[j] = dp[j-1] + triangle[i][j];
                else dp[j] = min(dp[j], dp[j-1]) + triangle[i][j];
            }
        }
        int ret = INT_MAX;
        for(int i=0; i<len; i++) {
            ret = min(ret, dp[i]);
        }
        return ret;
    }
};