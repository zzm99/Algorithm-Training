#include <cstdio>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>
using namespace std;

struct Edge {
    int to;
    int color;  // color = 0 -> red  | color = 1 -> black
    int weight;
    Edge(int t = 0, int c = 0, int w = 0) : to(t), color(c), weight(w) {}
};

struct Attribute {
    bool used;
    int color;
    int weight;
};

const int maxn = 20;
const int states = 1 << 21;
const int INF = INT_MAX;
Attribute m[maxn + 1][maxn + 1];

vector<Edge> matrix[maxn + 1];

bool visited[maxn + 1];
int n;

int dp[states][2];  // dp[i][j] 表示状态为i的树j先走的D的最大值
int subtree[maxn + 1];  // 子树的状态

void init() {
    for (int i = 0; i < maxn + 1; ++i) {
        for (int j = 0; j < maxn + 1; ++j)
            m[i][j].used = false;
        matrix[i].clear();
        visited[i] = false;
        subtree[i] = 0;
    }
    for (int i = 0; i < states; ++i) dp[i][0] = dp[i][1] = INF;
    dp[1][0] = dp[1][1] = 0;
}

void transform(int cur) {
    visited[cur] = true;
    vector<Edge> &vt = matrix[cur];
    for (int i = 0; i <= n; ++i) {
        if (!visited[i] && m[cur][i].used) {
            vt.push_back(Edge(i, m[cur][i].color, m[cur][i].weight));
            transform(i);
        }
    }
}

int subTree(int root) {
    vector<Edge> &vt = matrix[root];
    int state = 1 << root;
    for (int i = 0; i < vt.size(); ++i) {
        Edge &e = vt[i];
        state += subTree(e.to);
    }
    return subtree[root] = state;
}

int DP(int state, int color) {
    if (dp[state][color] != INF) return dp[state][color];

    if (color == 0) dp[state][color] = -INF;
    else dp[state][color] = INF;

    int tot[2] = { 0, 0 };
    bool canCut = false;

    queue<int> que;
    que.push(0);
    while (!que.empty()) {
        int cur = que.front(); que.pop();
        vector<Edge> &vt = matrix[cur];
        for (int i = 0; i < vt.size(); ++i) {
            Edge &e = vt[i];
            if (((1 << e.to) & state) == 0) continue;
            que.push(e.to);
            if (e.color == color) {
                canCut = true;  // 表示需要修剪的颜色为color时，可以找到可剪的树枝
                int weight = (color == 0 ? e.weight : -e.weight);
                int st = subtree[e.to]; // 包括e.to
                int next_state = state & (~st);
                int next_color = (color + 1) % 2;
                if (color == 0) {
                    dp[state][color] = max(dp[state][color], DP(next_state, next_color) + weight);
                } else {
                    dp[state][color] = min(dp[state][color], DP(next_state, next_color) + weight);
                }
            }
            tot[e.color] += (e.color == 0 ? e.weight : -e.weight);
        }
    }
    if (!canCut) dp[state][color] = tot[(color + 1) % 2];   // 如果全部都是另外一种情况，则另外一种情况必然全选
    return dp[state][color];
}

int main() {
    while (scanf("%d", &n) != EOF) {
        init();

        // 读入新红黑树
        int node1, node2, color, weight;
        for (int i = 0; i < n; ++i) {
            scanf("%d%d%d%d", &node1, &node2, &color, &weight);
            color = color == -1 ? 1 : 0;    // color = 0 -> red | color = 1 -> black
            m[node1][node2].used = m[node2][node1].used = true;
            m[node1][node2].color = m[node2][node1].color = color;
            m[node1][node2].weight = m[node2][node1].weight = weight;
        }

        // 转换新红黑树->邻接链表
        transform(0);
        // 构造每个子树的状态
        subTree(0);

        // 使用算法查找红黑树状态为（111...111），A均（砍红树）现行的D的最大值
        int state = (1 << (n + 1)) - 1;
        printf("%d\n", DP(state, 0));
    }
    return 0;
}