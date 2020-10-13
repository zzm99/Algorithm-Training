class Solution {
public:
    bool check(string a, string b) {
        int n = a.size();
        bool flag = true;
        for(int i=0; i<n/2; i++) {
            if(flag) {
                if(a[i] != b[n-i-1]) {
                    flag = false;
                    i--;
                }
            } else {
                if(a[i] != a[n-i-1]) {
                    return false;
                }
            }
        }
        return true;
    }
    bool checkPalindromeFormation(string a, string b) {
        if(check(a, b) || check(b, a)) return true;
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());    
        if(check(a, b) || check(b, a)) return true;
        return false;
    }
};
