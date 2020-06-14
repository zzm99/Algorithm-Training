#include <iostream>
#include <cmath>
using namespace std;
 
bool prime(int a)
{
    for(int i=2;i*i<=a;i++)
        if(a%i==0)
            return false;
    return true;
}
 
int main()
{
    int t;
    cin>>t;
    for(int i=3;i<t;i+=2)
    {
        if(!prime(i)) continue;
        long long s=pow(2.0,i)-1,s2;
        s2=s;
        bool b=0,b2=0;
        for(long long i=3;i*i<=s;i+=2)
        {
            if(s%i==0)
            {
                if(!b2) cout<<i;
                else cout<<" * "<<i;
                s/=i;
                i=3;
                b2++;
                b++;
            }
        }
        if(b)
        {
            cout<<" * "<<s;
            cout<<" = "<<s2<<" = ( 2 ^ "<<i<<" ) - 1"<<endl;
        }
    }
    return 0;
}