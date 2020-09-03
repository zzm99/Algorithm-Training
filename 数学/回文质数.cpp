#include <stdio.h>  
#include <string.h>  
int huiwen(int k)
{  
    int a[10],i=0,j;  
    while (k>0)  
    {  
        a[i]=k%10;  
        k/=10;  
        i++;  
    }  
    for (j=0; j<i; j++)  
        if (a[j]!=a[i-j-1])  
            return 0;  
    return 1;  
}   
int hwlength(int k)
{  
    int a[10],i=0;  
    while (k>0)  
    {  
        a[i]=k%10;  
        k/=10;  
        i++;  
    }  
    return (i);  
}  
int prime(int k) 
{  
    int i;  
    for (i=3; i*i<=k; i+=2)  
        if (k%i==0)  
            return 0;  
    return 1;  
}  
int extend(int k)
{  
    int i,s=1;  
    for (i=0; i<k; i++)  
        s*=10;  
    return (s);  
}  
int main()  
{  
    int a,b,i,j;  
    scanf("%d%d",&a,&b); 
	while(true) {
	 	if(a == 0 && b == 0) break;
	    for (i=a; i<=b; i++)  
	    {  
	        if (i%2==0&&i!=2)  
	            continue;  
	        if (i%5==0&&i!=5)  
	            continue;  
	        if (hwlength(i)%2==0&&i!=11)
	        {  
	            i=extend(hwlength(i));  
	            continue;  
	        }  
	        if (!huiwen(i))  
	            continue;  
	        if (prime(i))  
	            printf("%d\n",i);  
	    }  
	    scanf("%d%d",&a,&b); 
	}
    return 0;  
}  
