class Solution {
public:
    bool isNumber(string s) {
        if(s.empty()) return false;
        bool e = 0, dot = 0, num = 0;
        int lo = 0, hi = s.size()-1;
        while(lo<=hi && s[lo] == ' ') lo++;
        while(hi>=lo && s[hi] == ' ') hi--;
        if(hi < lo) return false;
        lo += (s[lo] == '+' || s[lo] == '-');
        for(int i=lo; i<=hi; i++){
            if(s[i] >= '0' && s[i] <= '9') num = 1;
            else if(s[i] == '.'){
                if(dot || e) return false;
                dot = 1;
            }
            else if(s[i] == 'e' || s[i] == 'E'){
                if(e || !num || i==hi) return false;
                if(s[i+1] == '+' || s[i+1] == '-') i++;
                e = 1; num = 0;
            }
            else return false;
        }
        return num;
    }
};