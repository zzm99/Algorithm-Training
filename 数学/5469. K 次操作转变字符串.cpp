class Solution {
public:
    bool canConvertString(string s, string t, int k) {
        if (s.size() != t.size())
            return false;
        vector<int> cnt(26);
        for (int i = 0; i < s.size(); ++i) {
            int delta = (t[i] - s[i] + 26) % 26;
            cnt[delta]++;
        }
        int hi = 0;
        for (int i = 1; i < 26; ++i)
            hi = max(hi, (cnt[i] - 1) * 26 + i);
        return hi <= k;
    }
};