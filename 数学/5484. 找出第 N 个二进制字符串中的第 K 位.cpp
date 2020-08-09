class Solution {
    string s[21],t[21];
public:
    char findKthBit(int n, int k) {
        s[1]="0";
        t[1]="1";
        for(int i=2;i<=n;i++)
        {
            s[i]=s[i-1];
            s[i]+='1';
            s[i]+=t[i-1];
            t[i]=s[i-1];
            t[i]+='0';
            t[i]+=t[i-1];
        }
        return s[n][k-1];
    }
};