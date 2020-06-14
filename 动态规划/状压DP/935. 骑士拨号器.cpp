class Solution {
public:
    const int M = 1e9+7;
    int knightDialer(int N) {
        vector<long> dp1(10, 1);
        vector<long> dp2(10, 0);
        for(int i=1; i<N; i++) {
            dp2[0] = (dp1[6] + dp1[4]) % M;
            dp2[1] = (dp1[6] + dp1[8]) % M;
            dp2[2] = (dp1[7] + dp1[9]) % M;
            dp2[3] = (dp1[4] + dp1[8]) % M;
            dp2[4] = (dp1[3] + dp1[9] + dp1[0]) % M;
            dp2[5] = 0;
            dp2[6] = (dp1[1] + dp1[7] + dp1[0]) % M;
            dp2[7] = (dp1[6] + dp1[2]) % M;
            dp2[8] = (dp1[1] + dp1[3]) % M;
            dp2[9] = (dp1[2] + dp1[4]) % M;
            dp1 = dp2;
        }
        long res = 0;
        for(int i=0; i<10; i++) {
            res = (res + dp1[i]) % M;
        }
        return (int)res;
    }
};
