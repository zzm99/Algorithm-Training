#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<int> cot(n);
        for(int i=0; i<n; i++) cin >> cot[i];
        sort(cot.begin(), cot.end(), [&](int a, int b){ return a > b; });
        int res = 0;
        int f = 0;
        for(int i=0; i<n; i++) {
            if(f == 2) res += cot[i];
            f++; f%=3;
        }
        cout << res << endl;
    }
    return 0;
}