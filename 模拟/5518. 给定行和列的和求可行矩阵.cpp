class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& a, vector<int>& b) {
        int m = a.size();
        int n = b.size();
        vector<vector<int>> ans(m, vector<int>(n));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                ans[i][j] = min(a[i], b[j]);
                a[i] -= ans[i][j];
                b[j] -= ans[i][j];
            }
        }
        return ans;
    }
};