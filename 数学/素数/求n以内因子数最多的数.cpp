#include <cstdio>
#include <iostream>
#define ULL unsigned long long

int p[16] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53};
ULL n;
ULL ans, ans_num;  
// ans 为 n 以内的最大反素数（会持续更新），ans_num 为 ans 的因子数。

void dfs(int depth, ULL temp, ULL num, int up) {
  if (depth >= 16 || temp > n) return;
  if (num > ans_num) {
    ans = temp;
    ans_num = num;
  }
  if (num == ans_num && ans > temp) ans = temp;
  for (int i = 1; i <= up; i++) {
    if (temp * p[depth] > n) break;
    dfs(depth + 1, temp *= p[depth], num * (i + 1), i);
  }
  return;
}

int main() {
  while (scanf("%llu", &n) != EOF) {
    ans_num = 0;
    dfs(0, 1, 1, 60);
    printf("%llu\n", ans);
  }
  return 0;
}