#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int t; cin >> t; 
    while(t--) {
        int a, b; cin >> a >> b;
        vector<int> sa(a+1), sb(b+1);
        for(int i=1; i<=a; i++) cin >> sa[i];
        for(int i=1; i<=b; i++) cin >> sb[i];
        vector<vector<int>> f(a+1, vector<int>(b+1));
        sort(sa.begin(), sa.end());
        sort(sb.begin(), sb.end());
        for(int i=0; i<=a; i++) {
            for(int j=0; j<=b; j++) {
                if(i == 0 && j == 0) {
                    f[i][j] = 0;
                } else if(j < i) f[i][j] = (1<<30);
                else {
                    f[i][j] = (1<<30);
                    if(i > 0) f[i][j] = min(f[i][j], f[i-1][j-1]+abs(sa[i]-sb[j]));
                    if(j > 0) f[i][j] = min(f[i][j], f[i][j-1]);
                }
            }
        }
        cout << f[a][b] << endl;
    }
    return 0;
}