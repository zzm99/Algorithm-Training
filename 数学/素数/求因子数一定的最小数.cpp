#include <stdio.h>
#define ULL unsigned long long
#define INF ~0ULL
ULL p[16] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53};

ULL ans;
ULL n;

// depth: 当前在枚举第几个素数。num: 当前因子数。
// temp: 当前因子数量为 num 的时候的数值。up：上一个素数的幂，这次应该小于等于这个幂次嘛, 不然ans就更加大拉

void dfs(ULL depth, ULL temp, ULL num, ULL up) {
	if(num > n || depth >= 16) return;
	if(num == n && ans > temp) {
		ans = temp;
		return;
	}
	for(int i=1; i<=up; i++) {
		if(temp / p[depth] > ans) break;
		dfs(depth+1, temp = temp*p[depth], num*(i+1), i);
	}
}

int main() {
	while(scanf("%llu", &n) != EOF) {
		ans = INF;
		dfs(0, 1, 1, 64);
		printf("%llu\n", ans);
	}
	return 0;
}
