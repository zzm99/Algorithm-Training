class Solution {
public:
    int getKthMagicNumber(int k) {
        int i3 = 0, i5 = 0, i7 = 0;
        vector<int> dp(k);
        dp[0] = 1;
        for(int i=1; i<k; i++) {
            dp[i] = min(min(3*dp[i3], 5*dp[i5]), 7*dp[i7]);
            if(dp[i]==3*dp[i3]) i3++;
            if(dp[i]==5*dp[i5]) i5++;
            if(dp[i]==7*dp[i7]) i7++;
        }
        return dp[k-1];
    }
};