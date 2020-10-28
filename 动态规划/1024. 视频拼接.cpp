class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int T) {
        vector<int> dp(T + 1, INT_MAX - 1);
        dp[0] = 0;
        for (int i = 1; i <= T; i++) {
            for (auto& it : clips) {
                if (it[0] < i && i <= it[1]) {
                    dp[i] = min(dp[i], dp[it[0]] + 1);
                }
            }
        }
        return dp[T] == INT_MAX - 1 ? -1 : dp[T];
    }
};

class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int T) {
        sort(clips.begin(), clips.end());
        int ans = 1;

        int end = 0;
        int next = 0;
        for (auto c : clips) {
            if (c[0] > end) {
                if (next >= T) break;
                ans++;
                end = next;
                if (c[0] > end) return -1;
            }
            next = max(next, c[1]);
        }
        return (next < T) ? -1 : ans;
    }
};