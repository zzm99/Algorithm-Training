#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    int t; cin >> t;
    while(t--) {
        string tmp; cin >> tmp;
        vector<char> cot;
        string res = "";
        for(int i=0; i<tmp.size(); i++) {
            if(tmp[i] == '0') {
                sort(cot.begin(), cot.end(), [&](char a, char b){ return a > b; });
                for(auto c: cot) res += c;
                res += '0';
                cot.clear();
            } else {
                cot.push_back(tmp[i]);
            }
        }
        if(cot.size() != 0) {
            sort(cot.begin(), cot.end(), [&](char a, char b){ return a > b; });
            for(auto c: cot) res += c;
        }
        cout << res << endl;
    }
    return 0;
}