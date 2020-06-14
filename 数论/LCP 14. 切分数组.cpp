class Solution {
    const int inf = 1e6 + 1;
    vector<int> largestPrime;
    vector<int> dp;
    void init (int n) {
        largestPrime = vector<int>(n + 1, 0);
        for (int i = 2; i <= n; i++) {
            if (!largestPrime[i]) {
                for (int j = i; j <= n; j += i) {
                    largestPrime[j] = i;
                }
            }
        }
    }
public:
    int splitArray(vector<int>& nums) {
        int ma = inf;
        init(ma);
        dp = vector<int>(inf, inf);
        int ans = 0;
        for (auto n : nums) {
            int temp = inf;
            while (n > 1) {
                int p = largestPrime[n];
                dp[p] = min(dp[p], ans);
                temp = min(temp, dp[p] + 1);
                while (!(n % p)) n /= p;
            }
            ans = temp;
        }
        return ans;
    }
};
