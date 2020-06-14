#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dp[101][101];

int main() {
    dp[1][0] = 1;
    for(int i=2; i<101; i++) {
        dp[i][0] = 1;
        for(int j=1; j<i; j++) {
            dp[i][j] = (dp[i-1][j]*(j+1) + dp[i-1][j-1]*(i-j)) % 2007;
        }
    }
    int a, b;
    while(cin >> a >> b) {
        cout << dp[a][b] << endl;
    }
    return 0;
}