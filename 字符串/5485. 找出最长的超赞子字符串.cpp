class Solution {
public:
    int longestAwesome(string s) {
        vector<int> first(1 << 10, -1);
        vector<int> good = {0};
        for (int i = 0; i < 10; ++i)
            good.emplace_back(1 << i);
        first[0] = 0;
        int n = s.size(), state = 0;
        int ans = 0;
        for (int i = 1; i <= n; ++i) {
            int c = s[i - 1] - '0';
            state ^= (1 << c);
            if (first[state] == -1)
                first[state] = i;
            for (int g : good) {
                int need = g ^ state;
                if (first[need] != -1)
                    ans = max(ans, i - first[need]);
            }
        }
        return ans;
    }
};