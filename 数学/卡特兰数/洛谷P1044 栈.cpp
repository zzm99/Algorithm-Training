// 入栈顺序为1,2,...,n  ，求所有可能的出栈顺序的总数。
#include <iostream>
using namespace std;
int n;
long long f[25];
int main() {
  f[0] = 1;
  cin >> n;
  for (int i = 1; i <= n; i++) f[i] = f[i - 1] * (4 * i - 2) / (i + 1);
  //这里用的是常见公式2
  cout << f[n] << endl;
  return 0;
}