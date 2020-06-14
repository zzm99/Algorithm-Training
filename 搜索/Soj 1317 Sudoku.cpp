#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
 
#define N 12
char square[N][N], ans[N][N];
bool row[N][N], col[N][N], blo[N][N];
int todo, num;
int block(int i, int j) {return (i-1)/3*3 + (j-1)/3 + 1;}
struct TODO
{
	int x, y, b, pNum;
	TODO() {}
	TODO(int _x, int _y): x(_x), y(_y), b(block(_x,_y)), pNum(0) {}
	void calc()
	{
		for (int i = 1; i <= 9; ++ i)
			if (!row[x][i] && !col[y][i] && !blo[b][i])
				pNum ++;
	}
};
bool cmp(const TODO &a, const TODO &b) {return a.pNum < b.pNum;}
TODO p[85];
void dfs(int n)
{
	if (n == todo)
	{
		num ++;
		if (num == 1) memcpy(ans, square, sizeof(square));
		return;
	}
	int xx = p[n].x, yy = p[n].y, bl = p[n].b;
	for (int temp = 1; temp <= 9; ++ temp)
	{
		if (!row[xx][temp] && !col[yy][temp] && !blo[bl][temp])
		{
			square[xx][yy] = temp+'0';
			row[xx][temp] = 1; col[yy][temp] = 1; blo[bl][temp] = 1;
			dfs(n+1);
			row[xx][temp] = 0; col[yy][temp] = 0; blo[bl][temp] = 0;
		}
	}
}
 
int main()
{
	int t;
	scanf("%d", &t);
	for (int Case = 1; Case <= t; ++ Case)
	{
		if (Case != 1) printf("\n");
		num = 0; todo = 0;
		memset(row, false , sizeof(row));
		memset(col, false , sizeof(col));
		memset(blo, false , sizeof(blo));
		for (int i = 1; i <= 9; ++ i)
		{
			scanf("%s", square[i]+1);
			for (int j = 1; j <= 9; ++ j)
			{
				if (square[i][j] == '_')
					p[todo++] = TODO(i,j);
				else
				{
					row[i][square[i][j]-'0'] = 1;
					col[j][square[i][j]-'0'] = 1;
					blo[block(i,j)][square[i][j]-'0'] = 1;
				}
			}
		}
		for (int i = 0; i < todo; ++ i) p[i].calc();
		sort(p, p+todo, cmp);
		dfs(0);
		if (num == 0) printf("Puzzle %d has no solution\n", Case);
		else if (num == 1)
		{
			printf("Puzzle %d solution is\n", Case);
			for (int i = 1; i <= 9; ++ i)
				printf("%s\n", ans[i]+1);
		}
		else printf("Puzzle %d has %d solutions\n", Case, num);
	}
}