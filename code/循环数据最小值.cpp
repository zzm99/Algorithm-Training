#include <iostream>
#include <vector>

using namespace std;

// 时间：O（log（n））
// 空间：O（1）
// 思路：使用二分查询算法不断逼近最小值，
//      当中间点小于右边界时，右边界可以设置为中点，
//      否则中点不会是最小值，左边界可以设置为中点+1。当left=right时候，退出，此时就是最小值。

int FindMin(vector<int>& vt) {
    int left = 0;
    int right = vt.size()-1;
    while (left < right) {
        int mid = (left + right) / 2;
        if (vt[mid] < vt[right]) {
            right = mid;
        } else {
            left = mid+1;
        }
    }
    return vt[left];
}

int main() {
    vector<int> vt = {50, 52, 63, 90, 3, 8, 15, 44, 45};
    cout << FindMin(vt) << endl;

    vector<int> vt1 = {1, 2, 3, 4, 5, 6};
    cout << FindMin(vt1) << endl;

    vector<int> vt2 = {8, 9, 10, 1, 2, 3, 4, 5, 6, 7};
    cout << FindMin(vt2) << endl;

    return 0;
}