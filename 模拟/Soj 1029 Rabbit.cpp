// 高精度加法
#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <map>
#include <string>
#include <stack>
using namespace std;
 
string bigIntAdd(string s1, string s2){
    string ans = "";
    if(s1.length() < s2.length())
        swap(s1, s2);
    int len = s1.size()-s2.size();
    for(int i = 0; i < len; i++)
        s2 = '0' + s2;
 
    int tmp1, tmp2, res, carry = 0;
    for(int i = s1.size()-1; i >=0; i--){
        tmp1 = s1[i]-'0', tmp2 = s2[i]-'0';
        res = (tmp1+tmp2+carry)%10;
        carry = (tmp1+tmp2+carry)/10;
        ans = char(res +'0') + ans;
        if(i == 0 && carry != 0)
            ans = '1' + ans;
    }
    return ans;
}
int main(){
   int m, d;
   while(cin >> m >> d && m && d){
        string res[105];
        res[0] = "1";
        for(int i = 1; i <= d; i++){
            if(i < m)
                res[i] = bigIntAdd(res[i-1], "1");
            else
                res[i] = bigIntAdd(res[i-1], res[i-m]);
        }
        cout << res[d] <<endl;
   }
 
}                                 