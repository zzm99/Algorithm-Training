class Solution {
public:
    int minScoreTriangulation(vector<int>& A) {
        int n = A.size();
        vector<vector<int>> dp(n, vector<int>(n, INT_MAX));
        for(int i=0; i<n-1; i++) dp[i][i+1] = 0;
        for(int i=n-1; i>=0; i--) {
            for(int j=i+1; j<n; j++) {
                for(int k=i+1; k<j; k++) {
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j] + A[i]*A[k]*A[j]);
                }
            }
        }
        return dp[0][n-1];
    }
};