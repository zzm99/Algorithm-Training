typedef long long ll;
const ll MOD = 1e9 + 7;

class Solution {
public:
    int numSub(string s) {
        int n = s.size();
        ll curr = 0, ans = 0;
        for (char c : s) {
            if (c == '1')
                curr++;
            else {
                ans += curr * (curr + 1) / 2;
                ans %= MOD;
                curr = 0;
            }
        }
        ans += curr * (curr + 1) / 2;
        ans %= MOD;
        return ans;
    }
};