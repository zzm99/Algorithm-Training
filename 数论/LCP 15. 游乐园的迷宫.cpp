class Solution {
private:
    pair<int, int> Sub(pair<int, int> a, pair<int, int> b) {
        // 求点 a 到点 b 的向量
        return make_pair(a.first - b.first, a.second - b.second);
    }

    int Cross(pair<int, int> a, pair<int, int> b) {
        // 求向量 a 到向量 b 的向量叉积
        return a.first * b.second - a.second * b.first;
    }
public:
    vector<int> visitOrder(vector< vector<int> >& points, string dir) {
        int n = points.size();
        vector<bool> used(n, false);  // 记录点的遍历情况， False未遍历 / True已遍历
        vector< pair<int, int> > point;
        vector<int> order; // 记录返回结果

        for (int i=0; i<n; ++i) {
            point.push_back( make_pair(points[i][0], points[i][1]) );
        }

        // 查找最左的点作为 起始点
        int start = 0;
        for (int i=1; i<n; ++i) {
            if (point[i] < point[start]) {
                start = i;
            }
        }
        used[start] = true;
        order.push_back(start);

        for (int i=0; i<dir.size(); ++i) {
            int next = -1;
            if (dir[i] == 'L') {
                // 转向方向为 L，选择相对方向最右的点
                for (int j=0; j<n; ++j) {
                    if (!used[j]) {
                        if (next == -1 || Cross(Sub(point[next], point[start]), Sub(point[j], point[start])) < 0) {
                            next = j;
                        }
                    } 
                }
            } else if (dir[i] == 'R') {
                // 转向方向为 R，选择相对方向最左的点
                for (int j=0; j<n; ++j) {
                    if (!used[j]) {
                        if (next == -1 || Cross(Sub(point[next], point[start]), Sub(point[j], point[start])) > 0) {
                            next = j;
                        }
                    } 
                }
            }
            // 返回结果加入选择的点，更新下一次转向的起点
            used[next] = true;
            order.push_back(next);
            start = next;
        }
        // 添加最后一个剩余点
        for (int i=0; i<n; ++i) {
            if (used[i] == false) {
                order.push_back(i);
            }
        }
        return order;
    }
};
