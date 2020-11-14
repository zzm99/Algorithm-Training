class Solution {
public:
    int myAtoi(string str) {
        int n = str.size();
        int idx = 0;
        while(idx < n && str[idx] == ' ') idx++;
        if(idx == n) return 0;
        
        bool negative = false;
        if(str[idx] == '-') {
            negative = true;
            idx++;
        } else if(str[idx] == '+') {
            idx++;
        } else if(!(str[idx] >= '0' && str[idx] <= '9')) {
            return 0;
        }

        int ans = 0;
        while(idx < n && (str[idx] >= '0' && str[idx] <= '9')) {
            int digit = str[idx]-'0';
            if(ans > (INT_MAX-digit)/10) { // [−2^31,  2^31 − 1]
                return negative ? INT_MIN : INT_MAX;
            }
            ans = ans * 10 + digit;
            idx++;
        }
        return negative ? -ans : ans;
    }
};