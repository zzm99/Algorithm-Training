#include <iostream>
#include <string>
#include <map>
using namespace std;

// 时间：O（n）
// 空间：O（1）
// 思路：分别计算和对比两个字符串中各个字母的总数，计算过程为递归地计算括号内的字符串并根据括号前的符号来决定递归回溯后累计方式是加还是减

int Calc(string& s1, int idx, map<int, int>& mp) {
    int i = idx;
    while (i < s1.size()) {
        if (s1[i] == '(') {
            map<int, int> tmp;
            int nextIdx = Calc(s1, i+1, tmp);
            for (auto& kv: tmp) {
                if (i > 0 && s1[i-1] == '-') {
                    mp[kv.first] -= kv.second;
                } else {
                    mp[kv.first] += kv.second;
                }
            }
            i = nextIdx;
        } else if (s1[i] == ')') {
            i++;
            return i;
        } else {
            if (i > 0 && s1[i-1] == '-') {
                mp[s1[i]-'a']--;
            } else {
                mp[s1[i]-'a']++;
            }
            i++;
        }
    }
    return i;
}

bool Compare(string& s1, string& s2) {
    map<int, int> mp1;
    Calc(s1, 0, mp1);

    map<int, int> mp2;
    Calc(s2, 0, mp2);

    for (int i = 0; i < 26; i++) {
        if (mp1[i] != mp2[i]) {
            return false;
        }
    }
    return true;
}

int main() {
    string s1 = "a+b+c-a";
    string s2 = "(b+c)";

    if (Compare(s1, s2)) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }

    string s3 = "a+d";
    string s4 = "b+c";

    if (Compare(s3, s4)) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }

    string s5 = "a+c";
    string s6 = "a-(b-(b+c))";

    if (Compare(s5, s6)) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }

    return 0;
}