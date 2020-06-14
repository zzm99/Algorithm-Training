class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end());
        int n = envelopes.size();
        if(n == 0) return 0;
        vector<int> dp(n, 1);
        int cmax = 1;
        for(int i=1; i<n; i++) {
            for(int j=0; j<i; j++) {
                if(envelopes[i][0] > envelopes[j][0] && envelopes[i][1] > envelopes[j][1])
                    dp[i] = max(dp[i], dp[j]+1);
            }
            cmax = max(cmax, dp[i]);
        }
        return cmax;
    }
};