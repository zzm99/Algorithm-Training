#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
 
int ans[23][23][23];
int cost[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
 
inline int getCost(int n) {
    if (n == 0) return 6;
    int r = 0;
    if (n < 0) {
        r = 1;
        n = -n;
    }
    while (n) {
        r += cost[n % 10];
        n /= 10;
    }
    return r;
}
 
void init() {
    int a, b, c;
    for (int i = -999; i < 1000; i++) {
        a = getCost(i);
        for (int j = -999; j < 1000; j++) {
            b = getCost(j);
            c = i + j;
            if (-999 <= c && c <= 999) ans[a][b][getCost(c)]++;
            c = i - j;
            if (-999 <= c && c <= 999) ans[a][b][getCost(c)]++;
            c = i * j;
            if (-999 <= c && c <= 999) ans[a][b][getCost(c)]++;
            if (j == 0) continue;
            c = i / j;
            if (-999 <= c && c <= 999) ans[a][b][getCost(c)]++;
        }
    }
}
 
int main() {
    init();
    while (1) {
        int a, b, c;
        cin >> a;
        if (a == 0) break;
        cin >> b >> c;
        if (a > 110 || b > 110 || c > 110) cout << "0 solutions for " << a << " " << b << " " << c << endl;
        else if (ans[a / 5][b / 5][c / 5] == 1) cout << "1 solution for " << a << " " << b << " " << c << endl;
        else cout << ans[a / 5][b / 5][c / 5] << " solutions for " << a << " " << b << " " << c << endl;
    }
    return 0;
}                                 