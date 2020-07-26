class Solution {
public:
    int minFlips(string target) {
        int flag = true;
        int res = 0;
        for(int i=0; i<target.size(); i++) {
            if(flag && target[i] == '1') {
                flag = false;
                res++;
            } else if(flag == false && target[i] == '0') {
                flag = true;
                res++;
            }
        }
        return res;
    }
};