#include <iostream>
#include <cstdio>
#include <cstring>
 
using namespace std;
 
int m, n;
int res;
int dx[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int dy[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };
int d[16][16], tar[16][16];
 
void cal() {
	int around, _new;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++) {
			around = 0;
			for (int k = 0; k < 8; k++)
				// 省去对越界的判断
				if (d[(i + dx[k] + m) % m][(j + dy[k] + n) % n])
					around++;
 
			if (around == 3)
				_new = 1;
			else if (d[i][j] == 1 && around == 2)
				_new = 1;
			else
				_new = 0;
 
			// 生成一个格子判断一下
			if (tar[i][j] != _new)
				return;
		}
 
	res++;
	return;
}
 
void dfs(int x, int y) {
	if (x == m) {
		cal();
		return;
	}
 
	// 利用DFS遍历状态
	d[x][y] = 0;
	if (y == n - 1)
		dfs(x + 1, 0);
	else
		dfs(x, y + 1);
	d[x][y] = 1;
	if (y == n - 1)
		dfs(x + 1, 0);
	else
		dfs(x, y + 1);
}
 
int main(int argc, char **argv) {
	int C = 1;
	while (cin >> m >> n && (m | n)) {
		memset(tar, 0, sizeof(tar));
 
		int k;
		scanf("%d", &k);
 
		int x, y;
		for (int i = 0; i < k; ++i) {
			scanf("%d%d", &x, &y);
			tar[x][y] = 1;
		}
 
		res = 0;
		dfs(0, 0);
 
		if (res)
			printf("Case %d: %d possible ancestors.\n", C++, res);
		else
			printf("Case %d: Garden of Eden.\n", C++);
	}
	return 0;
}
 