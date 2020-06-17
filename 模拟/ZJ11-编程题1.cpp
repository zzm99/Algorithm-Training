//按照y值从大到小排序，然后扫描，保存当前最大的x，如果该点比x大，那么该点满足条件
//注意要使用scanf,printf,使用cin,cout会超时
 
#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
struct node{
    int x;
    int y;
};
 
bool cmp(node n1, node n2){
    return n1.y>n2.y;
}
node no[500001];
int main(){
    int n;
    while(scanf("%d", &n)!=EOF){
        for(int i = 0; i < n; i++)
        {
            scanf("%d%d", &no[i].x, &no[i].y);
        }
        sort(no,no+n,cmp);
        int mmax = -1;
        for(int i = 0; i < n; i++)
        {
            if(no[i].x>mmax)
            {
                mmax=no[i].x;
                printf("%d %d\n", no[i].x ,no[i].y);
            }
        }
 
    }
    return 0;
}