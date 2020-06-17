#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n; cin >> n;
    vector<int> t(n);
    for(int i=0; i<n; i++) cin >> t[i];
    sort(t.begin(), t.end());
    int res = 0;
    int i = 0;
    while(i < t.size()) {
        int a = i, b = i+1, c = i+2;
        if(b >= t.size()) {
            res += 2; break;
        } else if(c >= t.size()) {
            if((b-a) <= 20) res += 1;
            else res += 4;
            break;
        }
        if((b-a)<=10 && (c-b)<=10) {
            i += 3; continue;
        }
        if((b-a)<=20) {
           res += 1; i += 2;
            continue;
        }
        res += 2;
        i += 1;
    }
    cout << res;
    return 0;
}