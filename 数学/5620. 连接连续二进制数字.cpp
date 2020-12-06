const int MOD = 1e9 + 7;
class Solution {
public:
    int concatenatedBinary(int n) {
        int ret = 0;
        for (int i = 1; i <= n; ++i) {
            string cur;
            for (int t = i; t; t /= 2) cur += (char)('0' + t % 2);
            for (int j = cur.size() - 1; j >= 0; --j) {
                ret = ret * 2 + (cur[j] - '0');
                if (ret >= MOD) ret -= MOD;
            }
        }
        return ret;
    }
};