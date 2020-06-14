class Solution {
public:
    double soupServings(int N) {
        if(N >= 4800) return 1.0;
        int myN = (int)ceil(N/25.0);
        vector<vector<double>> dp(myN+1, vector<double>(myN+1));
        dp[0][0] = 0.5;
        for(int i=1; i<myN+1; i++) {
            dp[i][0] = 0;
            dp[0][i] = 1;
        }
        for(int i=1; i<myN+1; i++) {
            int a1 = i-4>0 ? i-4: 0;
            int a2 = i-3>0 ? i-3: 0;
            int a3 = i-2>0 ? i-2: 0;
            int a4 = i-1>0 ? i-1: 0;
            for(int j=1; j<myN+1; j++) {
                int b1 = j;
                int b2 = j-1>0 ? j-1: 0;
                int b3 = j-2>0 ? j-2: 0;
                int b4 = j-3>0 ? j-3: 0;
                dp[i][j] = 0.25*(dp[a1][b1]+dp[a2][b2]+dp[a3][b3]+dp[a4][b4]);
            }
        }
        return dp[myN][myN];
    }
};