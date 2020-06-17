#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int main() {
    int n; cin >> n;
    while(n--) {
        int m; cin >> m;
        int curmax = 1;
        map<pair<int, int>, int> mp1; 
        for(int i=0; i<m; i++) {
            map<pair<int, int>, int> mp2;
            int t = 0; cin >> t;
            while(t--) {
                int a, b; cin >> a >> b;
                mp2[{a, b}]++;
            }
            for(auto i=mp1.begin(); i!=mp1.end(); ) {
                if(mp2[i->first]) i++;
                else i = mp1.erase(i);
            }
            for(auto i=mp2.begin(); i!=mp2.end(); i++) {
                mp1[i->first] += mp2[i->first];
                curmax = max(curmax, mp1[i->first]);
            }
        }
        cout << curmax << endl;
    }
    return 0;
}