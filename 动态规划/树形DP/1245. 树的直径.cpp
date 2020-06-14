/*
给定一棵无向树，返回它的直径：树中最长路径的 边 的数量。

树用一个数组给出，数组为 edges[i] = [u, v]，每个元素代表一条双向边连接结点 u 和 v。每个结点的编号为 {0, 1, ..., edges.length}。
*/

class Solution {
public:
    int ans;
    vector<vector<int>> graph;

    int dfs(int x, int fa) {
        int max1 = 0, max2 = 0;
        for (int v : graph[x])
            if (v != fa) {
                int t = dfs(v, x) + 1;
                if (max1 < t) {
                    max2 = max1;
                    max1 = t;
                } else if (max2 < t) {
                    max2 = t;
                }
            }

        ans = max(ans, (max1 + max2));
        return max1;
    }

    int treeDiameter(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        graph.resize(n);
        for (const auto &e : edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }
        ans = 0;

        dfs(0, -1);

        return ans;
    }
};