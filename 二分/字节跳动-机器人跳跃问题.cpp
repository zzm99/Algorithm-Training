#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
double l = 0, r = 1e8;

bool check(vector<int> tot, double st) {
    for(int i=0; i<tot.size(); i++) {
        if(tot[i] > st) st -= (tot[i]-st);
        else st += (st-tot[i]);
        if(st < 0) return false;
    }
    return true;
}

int main() {
    int n = 0; cin >> n;
    vector<int> tot(n);
    for(int i=0; i<n; i++) {
        cin >> tot[i];
    }
    double ret = 0;
    while(l < r) {
        double mid = (l+r)/2.0;
        if(check(tot, mid)) ret = mid, r = mid;
        else l = mid+1.0;
    }
    int cur = (int)ret;
    if(check(tot, (double)cur)) cout << cur;
    else cout << cur+1;
    return 0;
}

// 或

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int l = 1, r = 1e5;

bool check(vector<int> tot, int st) {
    for(int i=0; i<tot.size(); i++) {
        if(st > 1e5) return true;
        st = st + st - tot[i];
        if(st < 0) return false;
    }
    return true;
}

int main() {
    int n = 0; cin >> n;
    vector<int> tot(n);
    for(int i=0; i<n; i++) {
        cin >> tot[i];
    }
    while(l < r) {
        int mid = (l+r)/2;
        if(check(tot, mid)) r = mid;
        else l = mid+1;
    }
    cout << l;
    return 0;
}
