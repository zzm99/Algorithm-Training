class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid[0][0] == 1) return 0;
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<long long>> dp(m, vector<long long>(n));
        for(int i=0; i<m; i++) if(obstacleGrid[i][0]==0)dp[i][0] = 1; else break;
        for(int i=0; i<n; i++) if(obstacleGrid[0][i]==0)dp[0][i] = 1; else break;
        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++){
                if(obstacleGrid[i][j] == 0)
                {
                    long long  q = 0;
                    if(obstacleGrid[i-1][j] == 0) q += dp[i-1][j];
                    if(obstacleGrid[i][j-1] == 0) q += dp[i][j-1];
                    dp[i][j] = q;
                }
            }
        }
        return (int)dp[m-1][n-1];
    }
};