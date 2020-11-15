class Solution {
public:
    string removeKdigits(string num, int k) {
        vector<char> stk;
        for(auto& s: num) {
            while(stk.size() > 0 && stk.back() > s && k) {
                stk.pop_back();
                k--;
            }
            stk.push_back(s);
        }
        while(stk.size() > 0 && k) {
            stk.pop_back();
            k--;
        }
        string ans = "";
        bool isleadingzero = true;
        for(auto& s: stk) {
            if(isleadingzero == true && s == '0') {
                continue;
            }
            isleadingzero = false;
            ans += s;
        }
        return ans == "" ? "0" : ans;
    }
};