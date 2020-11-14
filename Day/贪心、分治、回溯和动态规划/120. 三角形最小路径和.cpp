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