#include <iostream>
#define maxn 20005
using namespace std;
char s[maxn];
int height1,height2;
int i;

void dfs(int a,int b)
{
    int tempson=0;
    while(s[i]=='d')
    {
        i++;
        tempson++;  //tempson 代表第几个 儿子
        dfs(a+1,b+tempson);
    }
    i++;
	height1=a>height1?a:height1;  
	height2=b>height2?b:height2; 
}

int main()
{
	int n=1;
    while(cin>>s)
    {
        if(s[0]=='#')
            break;
		i=0;
        height1=height2=0;
        dfs(0,0);
		cout<<"Tree "<<n  <<": "<<height1<<" => "<<height2<<endl;
		n++;
    }
	
	return 0;
}