#include<cstdio>
#include<cstring>
#include<iostream>
#include<queue>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
const int N=505;
int line[N][N];
int girl[N],used[N];
int k,m,n;
bool found(int x)
{
    for(int i=1; i<=n; i++)
    {
        if(line[x][i]&&!used[i])
        {
            used[i]=1;
            if(girl[i]==0||found(girl[i]))
            {
                girl[i]=x;
                return 1;
            }
        }
    }
    return 0;
}
int main()
{
    int x,y;
    while(scanf("%d",&k)&&k)
    {
        scanf("%d %d",&m,&n);
        memset(line,0,sizeof(line));
        memset(girl,0,sizeof(girl));
        for(int i=0; i<k; i++)
        {
            scanf("%d %d",&x,&y);
            line[x][y]=1;
        }
        int sum=0;
        for(int i=1; i<=m; i++)
        {
            memset(used,0,sizeof(used));
            if(found(i)) sum++;
        }
        printf("%d\n",sum);
    }
    return 0;
}