class Solution {
public:
    bool divisorGame(int N) {
        if(N == 1) return false;
        if(N == 2) return true;
        vector<bool> dp(N+1);
        dp[2] = true;
        for(int i=3; i<=N; i++){
            for(int j=1; j<i; j++){
                if(i % j == 0 && !dp[i-j]){
                    dp[i] = true; break;
                }
            }
        }
        return dp[N];
    }
};