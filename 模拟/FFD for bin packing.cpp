#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
 
int main() {
  int n, q;
  while(cin >> n) {
    cin >> q;
    vector<int> bins;
    vector<int> items(n);
    for(int i=0; i<n; i++) cin >> items[i];
    sort(items.begin(), items.end(), [&](int a, int b){ return a > b; });
    for(int i=0; i<n; i++) {
      int flag = 0;
      for(int j=0; j<bins.size(); j++) {
        if(bins[j] >= items[i]) {
          bins[j] -= items[i];
          flag = 1;
          break;
        }
      }
      if(flag == 0) {
        bins.push_back(q-items[i]);
      }
      sort(bins.begin(), bins.end());
    }
    cout << bins.size() << endl;
  }
  return 0;
}