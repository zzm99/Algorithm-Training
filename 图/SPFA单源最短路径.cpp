#include<iostream>
#include<vector>
#include<queue>
using namespace std;
const int maxz = 205;

vector<pair<int, int>>E[maxz];
int inq[maxz], dis[maxz];
int n, m;

int main()
{
    for (int i = 0; i < maxz; ++i) dis[i] = 1e9;
    while (cin >> n >> m) {
        for (int i = 1; i <= m; ++i) {
            int x, y, k;
            scanf("%d%d%d", &x, &y, &k);
            E[x].push_back(make_pair(y, k));
            E[y].push_back(make_pair(x, k));
        }
        int s, t;
        queue<int> q;
        q.push(s);
        inq[s] = 1;
        dis[s] = 0;
        while (!q.empty()) {
            int now = q.front(); q.pop();
            inq[now] = 0;
            for (int i = 1; i <= E[now].size(); ++i) {
                int v = E[now][i].first;
                if (dis[v] > dis[now] + E[now][i].second) {
                    dis[v] = dis[now] + E[now][i].second;
                    if (inq[v] == 0) {
                        inq[v] = 1;
                        q.push(v);
                    }
                }
 
            }
        }
        if (dis[t] == 1e9) printf("-1");
        else printf("%d\n", dis[t]);
    }
    return 0;
}