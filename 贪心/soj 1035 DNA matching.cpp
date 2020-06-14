#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<string> cot(n);
        for(int i=0; i<n; i++) cin >> cot[i];
        int res = 0;
        vector<int> vis(n);
        for(int i=0; i<n; i++) {
            if(vis[i] == 1) continue;
            for(int j=i+1; j<n; j++) {
                if(vis[j] == 1) continue;
                if(cot[i].size() != cot[j].size()) continue;
                int f = 0;
                for(int k=0; k<cot[i].size(); k++) {
                    if(cot[i][k] == 'A') {
                        if(cot[j][k] != 'T') {f = 1; break;}
                    }else if(cot[i][k] == 'T') {
                        if(cot[j][k] != 'A') {f = 1; break;}
                    }else if(cot[i][k] == 'G') {
                        if(cot[j][k] != 'C') {f = 1; break;}
                    }else if(cot[i][k] == 'C') {
                        if(cot[j][k] != 'G') {f = 1; break;}
                    }
                }
                if(f == 0) {res++; vis[j]=1; break;}
            }
        }
        cout << res << endl;
    }
    return 0;
}
