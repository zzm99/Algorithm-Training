#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;
int dis[10010];
int origin[10010],destination[10010],value[10010];
int n,m;

void Bellman_ford(int a)
{
    memset(dis,0x3f3f3f3f,sizeof(dis));
    dis[a]=0;
    for(int i=1;i<=n-1;i++)//更新n-1次
        for(int j=1;j<=m;j++)//更新每一条边
            dis[destination[j]]=min(dis[destination[j]],dis[origin[j]]+value[j]);//判断是否更新
} 

int main()
{
    cin>>n>>m;
    for(int i=1;i<=m;i++)
        cin>>origin[i]>>destination[i]>>value[i];
    Bellman_ford(1);
    for(int i=1;i<=n;i++)
        cout<<dis[i]<<" "; 
}