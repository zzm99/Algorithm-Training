using LL = long long;

class Solution {
private:
    constexpr static int mod = (int)1e9 + 7;
    
public:
    int gethash(const vector<int>& pre, const vector<int>& mul, int l, int r) {
        return (pre[r + 1] - (LL)pre[l] * mul[r - l + 1] % mod + mod) % mod;
    }
    
    int distinctEchoSubstrings(string text) {
        int n = text.size();
        
        int base = 31;
        vector<int> pre(n + 1), mul(n + 1);
        pre[0] = 0;
        mul[0] = 1;
        for (int i = 1; i <= n; ++i) {
            pre[i] = ((LL)pre[i - 1] * base + text[i - 1]) % mod;
            mul[i] = (LL)mul[i - 1] * base % mod;
        }
        
        unordered_set<int> seen[n];
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int l = j - i;
                if (j + l <= n) {
                    int hash_left = gethash(pre, mul, i, j - 1);
                    if (!seen[l - 1].count(hash_left) && hash_left == gethash(pre, mul, j, j + l - 1)) {
                        ++ans;
                        seen[l - 1].insert(hash_left);
                    }
                }
            }
        }
        return ans;
    }
};