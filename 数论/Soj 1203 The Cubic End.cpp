#include <iostream>  
#include <string>
 
using namespace std;
 
long long mulAndMod(long long x, long long y, long long mod) { 
    long long ret = 0;
    while(y) {
        if(y & 1) ret = (ret + x) % mod;
        x = x * 2 % mod;
        y >>= 1;
    }
    return ret;
}
 
long long cube(long long x, long long mod){  //  x^3 % y = (x^2 % y) * x % y
    return mulAndMod(mulAndMod(x, x, mod), x, mod);
}
 
int main() { 
    int t;
    long long result;  //  答案，从右向左一位位增加
    long long remain;  //  从右向左一位位地和待比较的数比较
    long long power;
    long long step;
    string str;  //  待比较的数
    int length;  //  待比较数的长度
 
    cin >> t;
    while (t--){
        cin >> str;
        length = str.length();
        remain = str[length - 1] - '0';  //  初始化，取待比较的数最低位
 
        if (remain == 1) result = 1;  //  待比较的数最低位若为1，则答案最低位为1
        else if (remain == 3) result = 7;  //  待比较的数最低位若为3，则答案最低位为7
        else if (remain == 7) result = 3;  //  待比较的数最低位若为7，则答案最低位为3
        else if (remain == 9) result = 9;  //  待比较的数最低位若为9，则答案最低位为9
 
        power = 10;
 
        for (int i = length - 2; i >= 0; --i){  //  从待比较数的倒数第二位开始
            remain += (str[i] - '0') * power;  //  更新remain值
 
            step = power;
            power *= 10;  //  若remain有两位，则模数为100；若remain有三位，则模数为1000……
            
            //  (result^3 % power)与remain比较，直到相等。此时result低位中对应remain的那几位已经确定
            while (cube(result, power) != remain){
                //  若remain有两位，则result每次加10即可；若remain有三位，则result每次加100即可……
                result += step;
            }
        }
        cout << result << '\n';
    }

    return 0;
}