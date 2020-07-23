class Solution {
public:
    bool oneEditAway(string first, string second) {
        int s1 = first.size(), s2 = second.size();
        if(abs(s1-s2) > 1) return false;
        if(s1 < s2) return oneEditAway(second, first);
        int edit = 0;
        for(int i=0; i<s1; i++) {
            if(first[i] != second[i-(s1-s2)*edit] && ++edit > 1) {
                return false;
            }
        }
        return true;
    }
};