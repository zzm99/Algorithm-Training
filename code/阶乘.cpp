#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// 时间 O（n * max（len（result））
// 空间 O（n）
// 思路：递归计算阶乘，大数通过字符串存储，乘法使用大数乘法实现方式

string MuliBigNum(string num1, int num2) {
    string ret;
    int carry = 0;

    for (int i = num1.size()-1; i >= 0; i--) {
        int cur = (num1[i]-'0')*num2 + carry;
        carry = cur / 10;
        cur %= 10;
        ret += to_string(cur);
    }

    while (carry) {
        int cur = carry;
        carry = cur / 10;
        cur %= 10;
        ret += to_string(cur);
    }

    reverse(ret.begin(), ret.end());
    return ret;
}

string Calc(int n) {
    if (n == 0 || n == 1) {
        return "1";
    }
    return MuliBigNum(Calc(n-1), n);
}

// 存储优化版
vector<string> nVec(2,"1");
string Fac(int x)   //递归函数
{
    if(x >= nVec.size()){
        nVec.push_back(MuliBigNum(Fac(x - 1), x));
    }
    return nVec[x];
}

int main() {
    cout << Calc(1) << endl;
    cout << Calc(5) << endl;
    cout << Calc(10) << endl;
    cout << Calc(30) << endl;


    cout << Fac(30) << endl;

    return 0;
}