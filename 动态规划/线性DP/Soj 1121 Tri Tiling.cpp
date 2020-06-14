#include <iostream>
using namespace std;

int f[16];
int g[16];

void init() {
    f[0] = 1;
    g[0] = 0;
    for(int i=1; i<16; i++) {
        f[i] = 3*f[i-1] + g[i-1];
        g[i] = 2*f[i-1] + g[i-1];
    }
}

int main() {
    int n;
    init();
    while(cin >> n) {
        if(n == -1) break;
        if(n % 2 == 1) cout << 0 << endl;
        else cout << f[n/2] << endl;
    }
    return 0;
}