#include <iostream>
using namespace std;

int main() {
    int a, b, c;
    int n = 1;
    while(cin >> a >> b >> c) {
        if(a == 0 && b == 0 && c == 0) break;
        int d = c % b; 
        if(d > a) d = a;
        int res = c/b*a + d;
        cout << "Case " << n << ": " << res << endl;
        n++;
    }
    return 0;
}