#include <iostream>
#include <cstring>
using namespace std;

// 时间：O（n）
// 空间：O（1）
// 思路：逐个对比转化为小写后的字母，如前缀都相等，再根据长度进行判断。

// const char * s1 和 char const * s1 都是值不能变
// char * const s1 是指针不能变
int strcasecmp(const char *s1, const char *s2) {
    const char *t1 = s1;
    const char *t2 = s2;
    while (*t1 && *t2) {
        if (tolower(*t1) != tolower(*t2)) {
            int ans = tolower(*t1) - tolower(*t2);
            if (ans > 0) {
                return 1;
            } else if (ans < 0) {
                return -1;
            } else {
                return 0;
            }
        }
        t1++;
        t2++;
    }

    int len1 = strlen(s1);
    int len2 = strlen(s2);
    if (len1 == len2) {
        return 0;
    } else if (len1 > len2) {
        return 1;
    } else {
        return -1;
    }
}

int main() {
    char *s1 = "aB,c*de";
    char *s2 = "AB,C*dE";

    cout << strcasecmp(s1, s2) << endl;

    char *s3 = "abc";
    char *s4 = "abcd";

    cout << strcasecmp(s3, s4) << endl;

    char *s5 = "abcde";
    char *s6 = "abcd";

    cout << strcasecmp(s5, s6) << endl;

    char *s7 = "abcde";
    char *s8 = "abcdf";

    cout << strcasecmp(s7, s8) << endl;
    return 0;
}