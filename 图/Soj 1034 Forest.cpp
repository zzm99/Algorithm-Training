#include<iostream>
#include<stdio.h>
#include<memory.h>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> a[105];    //存储每个点的邻接表
bool isforest;         // 是否是森林的判断
bool visit[105];       //是否访问过这一节点
int width[105];        //每一层的宽度
int depth,wid;         //森林的深度和宽度
int in[105];           // 保存每个节点的入度，根据定义，入度不能>=2

void dfs(int currvet,int level) {
    if(visit[currvet]) {
        isforest=false;
        return;
    }
    visit[currvet]=true;
    width[level]++;       
    if(wid<width[level]) wid=width[level];
    if(depth<level) depth=level;            
    for (int i = 0; i < a[currvet].size(); ++i) {
        dfs(a[currvet][i],level+1);
    }
}  

int main() {
    int vertex,edge;
    while(cin>>vertex>>edge,vertex) {
        for (int i = 0; i <= vertex; ++i) {
            visit[i]=false;
            width[i]=0;
            a[i].clear();
            in[i]=0;
        }
        wid=depth=0;
        isforest=true;
        for (int i = 0; i < edge; ++i) {
            int first,second;
            cin>>first>>second;
            a[first].push_back(second);
            in[second]++;
            if(in[second]>=2)
                isforest=false;
        }
        if(isforest) {
            for (int i = 1; i <= vertex; ++i) {
                if(!in[i])   
                    dfs(i,0); 
            }
        }  
        for (int i = 1; i <= vertex; ++i) {
            if(!visit[i])
          	   isforest=false;
        }
        if(!isforest) {
            cout<<"INVALID"<<endl;
            continue;
        } else cout<<depth<<" "<<wid<<endl;
    }
    return 0;
}  