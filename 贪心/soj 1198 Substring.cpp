#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<string> cot(n);
        for(int i=0; i<n; i++) cin >> cot[i];
        string res = "";
        sort(cot.begin(), cot.end(), [&](string a, string b){return (a+b) < (b+a);});
        for(int i=0; i<n; i++) res += cot[i];
        cout << res << endl;
    }
    return 0;
}