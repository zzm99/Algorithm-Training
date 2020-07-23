class Solution {
public:
    vector<int> findSquare(vector<vector<int>>& matrix) {
        int row = matrix.size(), column = matrix[0].size();
        //dp[i][j][0]代表(i,j)左侧连续0数量,dp[i][j][1]代表(i,j)上方连续0数量 该数量包含(i,j)自身
        vector<vector<vector<int>>> dp(row+1, vector<vector<int>>(column+1, vector<int>(2, 0)));
        auto res = vector<int>(3, 0);
        for(int i=1; i<=row; i++) {
            for(int j=1; j<=column; j++) {
                if(matrix[i-1][j-1] == 0) {
                    dp[i][j][0] += dp[i][j-1][0] + 1;
                    dp[i][j][1] += dp[i-1][j][1] + 1;
                    int len = min(dp[i][j][0], dp[i][j][1]);
                    while(len > 0) {
                        if(dp[i-len+1][j][0] >= len && dp[i][j-len+1][1] >= len) {
                            if(len > res[2]) res = {i-len, j-len, len};
                            break;
                        } else len--;
                    }
                }
            }
        }
        if(res[2] == 0) return {};
        return res;
    }
};