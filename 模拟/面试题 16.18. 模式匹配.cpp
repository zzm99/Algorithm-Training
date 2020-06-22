class Solution {
public:
    bool patternMatching(string pattern, string value) {
        if(pattern.empty()) return  value.empty();
        int a = 0, b = 0;
        char a_ = pattern[0];
        int flg = -1;
        for(int i=0; i<pattern.size(); i++) {
            if(pattern[i] == a_) a++;
            else {
                if(flg == -1) flg = i;
                b++;
            }
        }
        int size = value.size();
        if(b == 0) {
            string temp = value.substr(0, size/a);
            string res;
            while(a != 0) {
                res += temp;
                a--;
            }
            return res == value;
        }
        int max = size/a;
        for(int j=0; j<=max; j++) {
            if((size-j*a) % b != 0) continue;
            int bp = (size-j*a) / b;
            string atemp = value.substr(0, j);
            string btemp = value.substr(flg*j, bp);
            if(atemp == btemp) continue;
            string res;
            for(auto c: pattern) {
                if(c == a_) res += atemp;
                else res += btemp;
            }
            if(res == value) return true;
        }
        return false;
    }
};