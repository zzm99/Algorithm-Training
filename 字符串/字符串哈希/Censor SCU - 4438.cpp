#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;
typedef unsigned long long ll;
const int maxn = 5e6+5;
 
ll bas = 131;
char s[maxn],t[maxn];
char ans[maxn];

int main()
{
	while(~scanf("%s %s",s,t))
	{
		stack<ll> q;
		ll st = 1,cur = 0,p = 0;
		int len1 = strlen(s);
		int len2 = strlen(t);
		for(int i = 1; i <= len1; i++) st *= bas;
		for(int i = 0; i < len1; i++) p = p*bas+s[i];
		q.push(0);
		int cnt = 0;
		for(int i = 0; i < len2; i++)
		{
			ans[cnt] = t[i];
			cur = cur*bas+t[i];
			if(cnt >= len1-1)
			{
				if(cnt >= len1)
					cur = cur-st*ans[cnt-len1];
				q.push(cur);
				if(cur == p)
				{
					for(int j = 0; j < len1; j++)
						q.pop();
					cnt -= len1;
					cur = q.top();
				}
			}
			else
				q.push(cur);
			cnt++;
		}
		for(int i = 0; i < cnt; i++)
			printf("%c",ans[i]);
		printf("\n");
	}
	return 0;
}