#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
using namespace std;

const int maxn = 26;
int xx[4] = {-1,0,1,0};
int yy[4] = {0,1,0,-1};
int vis[4][maxn][maxn];
string mm[maxn];
int n, m;
int x1, y1;//起点
int x2, y2;//终点
struct node
{
    int x;
    int y;
    int step;
    int dir;//标记方向
};
int judge(int a, int b)
{
    if(a>=0 && a<n && b>=0 && b<m)
        return 1;
    return 0;
}
int BFS()
{
    memset(vis,-1,sizeof(vis));
    node frontt, next;
    queue<node> q;
    int tx, ty;
    for(int i = 0; i < 4; i++)
    {
        tx = x1 + xx[i];
        ty = y1 + yy[i];
        if(mm[tx][ty] != 'X')
        {
            frontt.x = tx;
            frontt.y = ty;
            frontt.step = 1;
            frontt.dir = i;
            q.push(frontt);
            vis[i][tx][ty] = 1;
        }
    }
    while(!q.empty())
    {
        frontt = q.front();
        q.pop();
        if(frontt.x == x2 && frontt.y == y2)
        {
            return frontt.step;
        }
        for(int i = 1; i <= 2; i++)
        {
            if(i == 1) next.dir = frontt.dir;//当前方向继续向前
            else next.dir = (frontt.dir+1)%4;//向当前方向的右方
            tx = frontt.x + xx[next.dir];
            ty = frontt.y + yy[next.dir];
            next.step = frontt.step+1;
            if(mm[tx][ty]!='X' && judge(tx,ty) && vis[next.dir][tx][ty]==-1)
            {
                next.x = tx;
                next.y = ty;
                vis[next.dir][tx][ty] = 1;
                q.push(next);
            }
        }
    }
}
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        cin >> n >> m;
        getchar();
        for(int i = 0; i < n; i++)
        {
            getline(cin, mm[i]);
        }
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(mm[i][j] == 'S')
                {
                    x1 = i;
                    y1 = j;
                }
                else if(mm[i][j] == 'F')
                {
                    x2 = i;
                    y2 = j;
                }
            }
        }
        int ans = BFS();
        cout << ans << endl;
    }
    return 0;
}
