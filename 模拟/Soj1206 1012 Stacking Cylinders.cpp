#include <bits/stdc++.h>
using namespace std;
double x[11];//一共 
double y[11];
 
void solve(double x1,double y1,double x2,double y2,double &x3,double &y3){
	double len=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
	double mid=sqrt(4-len*len/4);
	double mid_x=(x1+x2)/2;
	double mid_y=(y1+y2)/2;
	double cos_=(x2-x1)/len;
	double sin_=(y1-y2)/len;
	x3=sin_*mid+mid_x;
	y3=cos_*mid+mid_y;
}
int main(){
	int t;
	scanf("%d",&t);
	int tmp=t;
	while(t--){
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%lf",&x[i]);
			y[i]=1; 
		}
		sort(x+1,x+n+1);
		for(int i=n;i>=2;i--){
			for(int j=1;j<i;j++)
			solve(x[j],y[j],x[j+1],y[j+1],x[j],y[j]);
		}	
		printf("%d: %.4lf %.4lf\n",tmp-t,x[1],y[1]);
	}
} 