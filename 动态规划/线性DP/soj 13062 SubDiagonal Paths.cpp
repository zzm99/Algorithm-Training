#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    while(cin >> n) {
        if(n == 0) break;
        vector<vector<long long>> dp(n+1, vector<long long>(n+1));
        for(int i=0; i<=n; i++) {
            for(int j=0; j<=n; j++) {
                if(i == 0) dp[i][j] = 1;
                else if(i > j) dp[i][j] = 0;
                else {
                    dp[i][j] = dp[i-1][j]+dp[i][j-1];
                }
            }
        }
        cout << dp[n][n] << endl;
    }
    return 0;
}