#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
    int n;
    while(cin >> n) {
        vector<int> w(n);
        for(int i=0; i<n; i++) cin >> w[i];
        vector<vector<int>> f(2*n, vector<int>(2*n));
        for(int len = 2; len <= n; len++) {
            for(int i=0; i+len <= 2*n; i++) {
                int j = i+len-1;
                for(int k=i; k<j; k++) {
                    int tmp = f[i][k] + f[k+1][j];
                    tmp += w[i%n] * w[(k+1)%n] * w[(j+1)%n];
                    f[i][j] = max(f[i][j], tmp);
                }
            }
        }
        int ret = 0;
        for(int i=0; i<n; i++) {
            ret = max(ret, f[i][i+n-1]);
        }
        cout << ret << endl;
    }
    return 0;
}