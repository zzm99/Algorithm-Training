class Solution {
public:
    vector<int> dp;
    int tribonacci(int n) {
         dp.resize(38);
         dp[0] = 0; dp[1] = dp[2] = 1;
         return help(n);
    }
    int help(int n){
        if(n == 0) return 0;
        else if(dp[n]) return dp[n];
        dp[n] = help(n-3) + help(n-2) + help(n-1);
        return dp[n];
    }
};