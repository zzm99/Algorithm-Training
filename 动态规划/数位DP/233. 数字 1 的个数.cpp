class Solution {
public:
    int countDigitOne(int n) {
        if (n <= 0) return 0;
        string s = to_string(n);
        int res = 0;
        int len = s.size();
        for (int i = 0; i < len; i ++) {
            int n1 = i == 0? 0 : stoi(s.substr(0, i));
            int n2 = i == len - 1? 0 : stoi(s.substr(i + 1));
            if (s[i] == '1') {
                res += n1 * pow(10, len - 1 - i);
                res += n2 + 1;
            }
            else if (s[i] > '1') 
                res += (n1 + 1) * pow(10, len - 1 - i);         
            else 
                res += n1 * pow(10, len - 1 - i);
        }
        return res;
    }
};