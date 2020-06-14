#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

// 通过 不断地将大边加进来。直到存在一个完美匹配。这个匹配就是最佳匹配
// 最佳匹配是总权值最大的完美匹配，跟最大流不一样
// 每个左边的点都要找到一条增广路
// 左边点的顶标是所连边的最大值，而每次循环都是知道能找到增广路为止
// 找不到增广路的时候，就找当前右边没用过的点，但是牺牲最少的权，然后选择他来实现当前加入最大顶标对应的边

const int INF = 0x3f3f3f3f;
int w[1000][1000]; 
int line[1000], usex[1000], usey[1000], cx[1000], cy[1000];
int n, ans, m;

bool find(int x) {
	usex[x] = 1;
	for(int i=1; i<=m; i++) {
		if((usey[i] == 0) && (cx[x] + cy[i] == w[x][i])) {
			usey[i] = 1;
			if((line[i] == 0) || find(line[i])) {
				line[i] = x;
				return true;
			}
		}
	}
	return false;
}

int km() {
	for(int i=1; i<=n; i++) {
		while(true) {
			int d = INF;
			memset(usex, 0, sizeof(usex));
			memset(usey, 0, sizeof(usey));
			if(find(i)) break;
			for(int j=1; j<=n; j++) {
				if(usex[j]) {
					for(int k=1; k<=m; k++) {
						if(!usey[k]) {
							d = min(d, cx[j] + cy[k] - w[j][k]);
						}
					}
				}
			}
			if(d == INF) return -1;
			for(int j=1; j<=n; j++) if(usex[j]) cx[j] -= d;
			for(int j=1; j<=m; j++) if(usey[j]) cy[j] += d;
		}
	}
	ans = 0;
	for(int i=1; i<=m; i++) {
		ans += w[line[i]][i];
	}
	return ans;
}

int main() {
	while(~scanf("%d%d", &n, &m)) {
		memset(cy, 0, sizeof(cy));
		memset(w, 0, sizeof(w));
		memset(cx, 0, sizeof(cx));
		for(int i=1; i<=n; i++) {
			int d = 0;
			for(int j=1; j<=m; j++) {
				scanf("%d", &w[i][j]);
				d = max(d, w[i][j]);
			}
			cx[i] = d;
		}
		memset(line, 0, sizeof(line));
		printf("%d\n", km());
	}
	return 0;
}