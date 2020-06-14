class Solution {
public:
    int atMostNGivenDigitSet(vector<string>& D, int N) {
        string S = to_string(N);
        int K = S.size();
        vector<int> dp(K+1);
        dp[K] = 1;
        for(int i=K-1; i>=0; i--) {
            int s = S[i]-'0';
            for(auto d: D) {
                if((d[0]-'0') < s) dp[i] += pow(D.size(), K-i-1);
                else if((d[0]-'0') == s) dp[i] += dp[i+1];
            }
        }
        for(int i=1; i<K; i++) {
            dp[0] += pow(D.size(), i);
        }
        return dp[0];
    }
};

