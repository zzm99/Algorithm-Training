#include <iostream>

using namespace std;

int modFunction(string& num) {
    int len = num.size();
    int pre = 0;
    int current;
    int i = 0;
    while (i < len) {
        current = pre * 10 + num[i] - '0';
        pre = current % 2;
        current /= 2;
        num[i++] = current + '0';
    }
    if (num[0] == '0')
        num = num.substr(1, len-1);
    return pre;
}

int main(int argc, char const *argv[])
{
    int testNum;
    cin >> testNum;
    int caseNum = 0;
    string number;
    while (caseNum++ < testNum) {
        if (caseNum != 1)
            cout << endl;
        cin >> number;
        int num = 0;
        while (modFunction(number) == 0) {
            ++num;
        }
        cout << "Case " << caseNum << ": " << num + 1 << endl;
    }

    return 0;
}
