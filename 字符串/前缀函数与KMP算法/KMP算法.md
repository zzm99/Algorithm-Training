字符串匹配。给你两个字符串，寻找其中一个字符串是否包含另一个字符串，如果包含，返回包含的起始位置。
如下面两个字符串：

```cpp
char *str = "bacbababadababacambabacaddababacasdsd";
char *ptr = "ababaca";
```

```cpp
#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
 
using namespace std;
 
void makeNext(char s[],int next[])
{
    int len = strlen(s);
    next[0]=0;
    for(int i=1,k=0;i<len;i++)
    {
        while(k>0 && s[k]!=s[i])
            k=next[k-1];
        if(s[k]==s[i])
            k++;
        next[i]=k;
    }
}
 
int kmp(char t[],char s[])
{
    int len1 = strlen(t);
    int len2 = strlen(s);
    int next[len2];
    makeNext(s,next);
    for(int i=0,j=0;i<len1;i++)
    {
        while(j>0 && t[i]!=s[j])
        {
            j=next[j-1];
        }
        if(t[i]==s[j])
            j++;
        if(j==len2)
            return i-j+1;
    }
}
 
int main()
{
    char t[]="1234561123458412";
    char s[]="611";
    cout<<t<<endl;
    cout<<s<<endl;
    cout<<"下标为"<<kmp(t,s)<<endl;
}
 
```