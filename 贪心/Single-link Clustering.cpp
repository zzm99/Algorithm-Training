// 题目解释：对于n个二维空间点进行聚类，将n个二维空间点分成k类。这道题转化的思想就是，先生成最小生成树，然后删除k-1个最长边

// 输入：第一行为节点数n以及最终分类的类别数k（2<= k <= 100)，后面n行，每一行包括两个数表示二维空间的点

// 输出：第k-1长的边的长度

#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <iomanip>
using namespace std;
 
vector<double> lowc;
const int max_vertexs = 100;
double g[max_vertexs][max_vertexs];
int father[max_vertexs];

typedef struct point{
    int x;
    int y;
}P;

float CalDistance(point a, point b)
{
    return sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
}
 
int main(int argc, const char * argv[]) {
    int n,class_num;
    while (cin>> n >> class_num) {
        if (n == 0) break;
        int x,y;
        vector<point> v;
        v.clear();
        for (int i = 0; i < n; i++) {
            cin >> x >> y;
            point p1;
            p1.x = x;
            p1.y = y;
            v.push_back(p1);
        }
        for (int i = 0; i < n; i ++) {
            for (int j = i+1; j < n; j ++) {
                g[i][j] = g[j][i] = CalDistance(v[i], v[j]);
            }
        }
        lowc.clear();        // 使用prim算法求解最小生成树
        int i, j, k;
        double lowcost[max_vertexs];
        int closet[max_vertexs];
        int used[max_vertexs];
        for (int i = 0; i < n; i ++) {
            lowcost[i] = g[0][i];
            closet[i] = 0;
            used[i] = 0;
            father[i] = -1;
        }
        used[0] = 1;
        for (i = 1; i < n; i++) {
            j = 0;
            while (used[j]) {
                j++;
            }
            for (k = 0; k < n; k ++) {
                if (!used[k] && (lowcost[k] < lowcost[j])) {
                    j = k;
                }
            }
            father[j] = closet[j];
            lowc.push_back(lowcost[j]);
            used[j] = 1;
            for (k = 0; k < n; k ++) {
                if (!used[k] && (g[j][k] < lowcost[k])) {
                    lowcost[k] = g[j][k];
                    closet[k] = j;
                }
            }
        }
 
        sort(lowc.begin(), lowc.end());
        cout <<  setprecision(2) << setiosflags(ios::fixed)<< lowc[n-class_num] << endl;
        
    }
    return 0;
}