class Solution {
public:
    double new21Game(int N, int K, int W) {
        vector<double> dp(N+1, 0);
        double sum = 0;
        dp[0] = 1;
        if(0 < K) sum += dp[0];
        for(int i=1; i<=N; i++) {
            dp[i] = sum / W;
            if(i < K) sum += dp[i];
            if(i >= W) sum -= dp[i-W];
        }
        double ans = 0;
        for(int i=K; i<=N; i++) ans += dp[i];
        return ans;
    }
};