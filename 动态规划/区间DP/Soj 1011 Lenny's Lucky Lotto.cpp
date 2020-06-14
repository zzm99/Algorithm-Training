#include <iostream>

using namespace std;

long long f[11][2001];
long long s[11][2001];

int main() {
    int t; cin >> t;
    for(long long i=1; i<2001; i++) {
        f[1][i] = 1;
        s[1][i] = i;
    }
    for(int i=2; i<11; i++) {
        f[i][0] = s[i][0] = 0;
        for(int j=1; j<2001; j++) {
            f[i][j] = s[i-1][j/2];
            s[i][j] = s[i][j-1]+f[i][j];
        }
    }
    for(int i=1; i<=t; i++) {
        int n, m;
        cin >> n >> m;
        cout << "Case " << i << ": n = " << n << ", m = " << m << ", # lists = " << s[n][m] << endl;
    }
    return 0;
}