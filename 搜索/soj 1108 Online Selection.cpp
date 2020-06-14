//dp
//题意:
//n组数字，对第i组数字回答 1或0 答案与ai一样就加一分， 回答1跳到第 I1 组 回答0同理
//要求给定回答的次数 k、得分m，输出过程中最多选择多少次0
//初始从第0组开始回答
 
//dp[p][l][so] 下一组数组是p，当前已选择l次，得分so的最优解
#include <iostream>
#include <cstdio>
#include <cstring>
 
using namespace std;
 
int c, n, k, m;
int i0[20], i1[20],a[20];
int dp[25][35][35]; 
int main()
{
	while( scanf( "%d",&c ) && c != 0 )
	{
		scanf( "%d%d%d",&n,&k,&m );
		for( int i = 0;i < n;i++ )
			scanf( "%d%d%d",i0+i,i1+i,a+i );
		
		memset( dp,-1,sizeof(dp) );
		
		//初始化弄错WA了很多次呢
		dp[0][0][0] = 0;
		dp[ i0[0] ][1][1] = (( a[0] == 0 ) ? 1 : dp[ i0[0] ][1][1]);
		dp[ i0[0] ][1][0] = (( a[0] == 0 ) ? dp[ i0[0] ][1][0]: 1);
		dp[ i1[0] ][1][1] = (( a[0] == 1 ) ? 0 : dp[ i1[0] ][1][1]);
		dp[ i1[0] ][1][0] = (( a[0] == 1 ) ? dp[ i1[0] ][1][0]: 0);
 
		for( int l = 1;l < k;l++ )
		{
			for( int p = 0;p < n;p++ )
			{
				for( int so = 0;so <= m;so++ )
				{
					if( dp[p][l][so] != -1 )
					{
						if( a[p] == 0 )
						{
							dp[ i0[p] ][l+1][so+1] = max( dp[ i0[p] ][l+1][ so+1 ] , dp[p][l][so]+1 );
							dp[ i1[p] ][l+1][so]   = max( dp[ i1[p]][l+1][ so ], dp[p][l][so] );
						}
						else
						{
							dp[ i0[p] ][l+1][so]   = max( dp[ i0[p] ][l+1][ so ] ,dp[p][l][so] + 1 );
							dp[ i1[p] ][l+1][so+1] =  max( dp[ i1[p]][l+1][ so+1], dp[p][l][so] );
						}
					}
				}
			}
		}
 
		int result = dp[ 0 ][k][m];
		
		for( int i = 1;i < n;i++ )
		{
			if( result < dp[i][k][m] ) result = dp[i][k][m];
		}
		if( result < 0 ) result = 0;
		printf( "%d %d\n",c,result );
 
	}
}