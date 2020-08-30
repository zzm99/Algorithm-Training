class Solution {
public:
    string reverseWords(string s) {
        int i = 0, j = 1, n = s.size();
        while (j <= n) {
            if (j == n || s[j] == ' ') {
                reverse(s.begin() + i, s.begin() + j);
                i = j + 1;
            }
            j++;
        }
        return s;
    }
};