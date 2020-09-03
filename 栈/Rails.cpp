#include<stdio.h>
#include<stack>
using namespace std; 
int b[1010];
// https://blog.csdn.net/hdd871532887/article/details/50369831
// http://soj.acmm.club/contest_detail.php?cid=2803
int main()
{
	int i,n,k,t;
	stack<int> s;
	while(scanf("%d",&n) && n)
	{
		while(1){
			while(!s.empty()) 
			{
			   s.pop();
		    }
			k=t=0;
			scanf("%d",&b[0]);
			if(b[0]==0) break;
			for(i=1;i<n;i++)
		    	scanf("%d",&b[i]);
			for(i=1;i<=n;i++)
			{
				s.push(i);
				while(!s.empty()&&s.top()==b[k])
				{
					k++;
					s.pop();
				}
			}
			if(s.empty())
				printf("Yes\n");
			else
				printf("No\n");
		}
		printf("\n");
	}
}