class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m+1, vector<int>(n+1));
        for(auto& str: strs) {
            int n0 = count(str.begin(), str.end(), '0');
            int n1 = str.size()-n0;
            for(int j=m; j>=n0; j--) {
                for(int k=n; k>=n1; --k) {
                    dp[j][k] = max(dp[j][k], dp[j-n0][k-n1]+1);
                }
            }
        }
        return dp[m][n];
    }
};