class Solution {
public:
    vector<int> ans;
    vector<int> child_cnt;
    vector<int> path_len;
    vector<vector<int>> g;
    int node_num;
    
    void dfs1(int cur, int fa) {
        for (auto &x : g[cur]) {
            if (x == fa) continue;
            dfs1(x, cur);
            child_cnt[cur] += child_cnt[x];
            path_len[cur] += path_len[x];
            path_len[cur] += child_cnt[x];
        }
        child_cnt[cur] ++;
        return;
    }

    void dfs2(int cur, int fa) {
        if (fa == -1) ans[cur] = path_len[cur];
        else {
            ans[cur] = ans[fa] - child_cnt[cur] + node_num - child_cnt[cur];
        }
        for (auto x : g[cur]) {
            if (x == fa) continue;
            else dfs2(x, cur);
        }
    }


    vector<int> sumOfDistancesInTree(int N, vector<vector<int>>& edges) {
        node_num = N;
        ans = vector<int>(N);
        child_cnt = vector<int>(N);
        path_len = vector<int>(N);
        g = vector<vector<int>>(N);
        for (auto &x : edges) {
            g[x[0]].push_back(x[1]);
            g[x[1]].push_back(x[0]);
        }
        dfs1(0, -1);
        dfs2(0, -1);
        return ans;
    }
};

// 两遍DFS。

// 先将整棵树看做一个有根树。
// 第一次遍历的时候，求出每个节点为根的子树的节点个数以及其到其为根的子树中的所有节点的路径和。

// 第二次遍历的时候，每个节点利用其父亲节点的信息，来求出其通过父亲节点才能到达的其它节点的路径和。
