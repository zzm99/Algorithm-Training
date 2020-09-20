class Solution {
    long long mini[16][16], maxi[16][16];
public:
    int maxProductPath(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        mini[0][0] = maxi[0][0] = grid[0][0];
        for (int i = 1; i < m; ++i)
            mini[0][i] = maxi[0][i] = mini[0][i - 1] * grid[0][i];
        for (int i = 1; i < n; ++i){
            mini[i][0] = maxi[i][0] = mini[i - 1][0] * grid[i][0];
            for (int j = 1; j < m; ++j){
                mini[i][j] = min(mini[i - 1][j] * grid[i][j], mini[i][j - 1] * grid[i][j]);
                mini[i][j] = min(mini[i][j], maxi[i][j - 1] * grid[i][j]);
                mini[i][j] = min(mini[i][j], maxi[i - 1][j] * grid[i][j]);
                maxi[i][j] = max(maxi[i - 1][j] * grid[i][j], maxi[i][j - 1] * grid[i][j]);
                maxi[i][j] = max(maxi[i][j], mini[i][j - 1] * grid[i][j]);
                maxi[i][j] = max(maxi[i][j], mini[i - 1][j] * grid[i][j]);
            }
        }
        if (maxi[n - 1][m - 1] < 0) return -1;
        return maxi[n - 1][m - 1] % 1000000007ll;
    }
};