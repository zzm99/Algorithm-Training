#include <cstdio>
int ca, cb, ma, mb;
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
int main()
{
	while (scanf("%d%d%d%d",&ca,&cb,&ma,&mb) != EOF)
	{
		if ( ca==0 || ma==0 ) printf("%d\n", min(cb,mb));
		else if ( cb==0 || mb==0 ) printf("%d\n", min(ca,ma));
		else if ( ca < cb ) printf("%d\n", ca + min(cb,mb*(ca+1)) );
		else printf( "%d\n", cb+min(ca,ma*(cb+1)) );
	}
}