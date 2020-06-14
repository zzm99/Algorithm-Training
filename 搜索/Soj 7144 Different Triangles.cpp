#include<iostream>
 
using namespace std;
 
bool istriangle(int a, int b, int c){
    if(a+b>c&&a+c>b&&b+c>a&&a-b<c&&a-c<b&&b-c<a) return true;
    return false;
}
 
int arry[10001];
 
int main()  
{
    int n;
    cin >> n;
    while(n--){
        int num,count=0;
        cin >> num;
        for(int i=0; i < num; i++)
        cin >> arry[i];
        for(int i=2; i < num; i++)
            for(int d=1; d < i; d++)
                for(int h=0; h<d; h++){
                    if(i!=d&&i!=h&&d!=h){
                        if(istriangle(arry[i],arry[d],arry[h])) count++;
                    }
                }
    cout << count << endl;
    }
}                                 