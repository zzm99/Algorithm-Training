#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> tot;
vector<int> res;

bool ishu(vector<int> tot) {
    if(tot.empty()) return true;
    int count0 = 0;
    count0 = count(tot.begin(), tot.end(), tot[0]);
    if(tot.size() % 3 != 0 && count0 >= 2) {
        vector<int> newtot(tot.begin()+2, tot.end());
        if(ishu(newtot)) return true;
    }
    if(count0 >= 3) {
        vector<int> newtot(tot.begin()+3, tot.end());
        if(ishu(newtot)) return true;
    }
    if(count(tot.begin(), tot.end(), tot[0]+1) && count(tot.begin(), tot.end(), tot[0]+2)) {
        vector<int> newtot(tot.begin()+1, tot.end());
        newtot.erase(find(newtot.begin(), newtot.end(), tot[0]+1));
        newtot.erase(find(newtot.begin(), newtot.end(), tot[0]+2));
        if(ishu(newtot)) return true;
    }
    return false;
}

bool hupai(vector<int> tot, int n) {
    if(count(tot.begin(), tot.end(), n)==4) return false;
    tot.push_back(n);
    sort(tot.begin(), tot.end());
    return ishu(tot);
}

int main() {
    int c=0;
    for(int i=0; i<13; i++) {
        cin >> c;
        tot.push_back(c);
    }
    for(int i=1; i<=9; i++) {
        if(hupai(tot, i)) {
            res.push_back(i);
        }
    }
    if(res.empty()) cout << "0";
    else {
        for(auto i: res) {
            cout << i << " ";
        }
    }
    return 0;
}