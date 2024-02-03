#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 时间 O（3^4 * len(str)）
// 空间 O（len(str)）
// 思路：递归回溯的方式来计算出合法的IP

void CalcIP(string& str, vector<string>& result, int idx, string& cur, int cnt) {
    if (cnt == 4 && idx == str.size()) {
        // 这里不能直接popback，因为cur = cur.substr(0, cur.size()-1-i);回溯的地方是使用长度来去掉末尾的字符
        result.push_back(cur.substr(0, cur.size()-1));
        return;
    }

    if (cnt == 4 || idx == str.size()) {
        return;
    }

    for (int i = 1; i <= 3; i++) {
        if (idx + i > str.size()) {
            return;
        }
        if (str[idx] == '0' && i != 1) {
            return;
        }
        if (i == 3 && str.substr(idx, i) > "255") {
            return;
        }
        cur += str.substr(idx, i);
        cur += ".";
        CalcIP(str, result, idx+i, cur, cnt+1);
        cur = cur.substr(0, cur.size()-1-i);
    }

}

int main() {
    string str = "25525511135";
    vector<string> vt;
    string cur = "";
    CalcIP(str, vt, 0, cur, 0);

    for (auto& ip: vt) {
        cout << ip << " ";
    }
    cout << endl;

    return 0;
}