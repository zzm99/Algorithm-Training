/*
给定平面上N个长方形，其两边都与坐标轴x轴和y轴平行，
通过4个长度均为N的数组给出每个长方形的左下角和右上角坐标。
其中xl[i], yl[i]为第i个长方形的左下角坐标，xh[i],yh[i]为第i个长方形的右上角坐标。
求任选其中k个长方形，其最大相交面积是多少？

2 <= N <= 200;
1 <= xl[i] <= xh[i] <= 1e9
1 <= yl[i] <= yh[i] <= 1e9
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	long maxIntersection(vector<int>& xl, vector<int>& yl, vector<int>& xh, vector<int>& yh, int k) {
		int length = xl.size();
		if(k > length || k < 0) return -1;
		vector<vector<vector<int>>> dp(length, vector<vector<int>>(k+1, vector<int>(4)));
		// 分别对应 第几个矩形 / 选了多少个矩形 / 相交矩形的坐标
		for(int i=0; i<length; i++) {
			dp[i][1][0] = min(xl[i], xh[i]);
			dp[i][1][1] = min(yl[i], yh[i]);
			dp[i][1][2] = max(xl[i], xh[i]);
			dp[i][1][3] = max(yl[i], yh[i]);
		}
		for(int i=1; i<length; i++) {
			for(int j=2; j<=k; j++) {
				vector<int> intersection(4);
				for(int l=(j-1)-1; l<i; l++) {
                    intersection=maxRectangle(intersection, intersect(dp[l][j-1], xl[i], yl[i], xh[i], yh[i]));
				}
				dp[i][j] = intersection;
			}
		}
		long ans = 0;
		for(int i=k-1; i<length; i++) {
			ans = max(ans, getArea(dp[i][k]));
		}
		return ans;
	}
	vector<int> intersect(vector<int> ls, int xll, int yll, int xhh, int yhh) {
		if (xll > xhh) {
			xll = xll ^ xhh;
			xhh = xll ^ xhh;
			xll = xll ^ xhh;
		}
		if (yll > yhh) {
			yll = yll ^ yhh;
			yhh = yll ^ yhh;
			yll = yll ^ yhh;
		}
		if (xhh < ls[0] || ls[2] < xll || yhh < ls[1] || ls[3] < yll) {
			return {0,0,0,0};
		}
		vector<int> res(4);
		res[0] = max(ls[0], xll);
		res[1] = max(ls[1], yll);
		res[2] = min(ls[2], xhh);
		res[3] = min(ls[3], yhh);
		return res;
	}
	long getArea(vector<int>& rectangle) {
		return (rectangle[2] - rectangle[0]) * (rectangle[3] - rectangle[1]);
	}
	vector<int> maxRectangle(vector<int> r1, vector<int> r2) {
		return getArea(r1) > getArea(r2) ? r1 : r2;
	}
};


int main() {
    Solution s;
    vector<int> a = {1, 2, 3};
    vector<int> b = {1, 2, 3};
    vector<int> c = {10, 9,8};
    vector<int> d = {10, 9, 8};
    int k = 2;
    cout << s.maxIntersection(a,b,c,d,k);
	return 0;
}
