#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cmath>
using namespace std;

int main() {
    int n;
    while(cin >> n) {
        vector<int> x(n);
        vector<int> y(n);
        for(int i=0; i<n; i++) {cin >> x[i] >> y[i];}
        vector<vector<double>> d(n, vector<double>(n));
        vector<vector<double>> f(n, vector<double>(n));
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                d[i][j] = sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
            }
        }
        f[0][1] = d[0][1];
        for(int k=2; k<n; k++) {
            for(int i=0; i<k-1; i++) {
                f[i][k] = f[i][k-1] + d[k-1][k];
            }
            f[k-1][k] = 1<<30;
            for(int i=0; i<k-1; i++) {
                f[k-1][k] = min(f[k-1][k], f[i][k-1]+d[i][k]);
            }
        }
        printf("%.2lf\n", f[n-2][n-1] + d[n-2][n-1]);
    }
    return 0;
}