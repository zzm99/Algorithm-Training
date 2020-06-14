#include<bits/stdc++.h>
using namespace std;

const int N = 100;
int n, q, a, b, c = 0, depth[N], visit[N], father[N][N];
vector<int> g[N];

void dfs(int x, int d) {
    depth[x] = d;
    visit[x] = 1;
    for(int i = 0; i < g[x].size(); i++)
        if(!visit[g[x][i]]) dfs(g[x][i], d + 1);
}

void init(int n) {
    for(int j = 1; j < c; j++)
        for(int i = 1; i <= n; i++)
            if(father[i][j - 1])
                father[i][j] = father[father[i][j - 1]][j - 1];
}

int lca(int u, int v) {
    if(depth[u] < depth[v]) swap(u, v);
    for(int i = c; i >= 0; i--) 
        if(depth[father[u][i]] >= depth[v]) 
            u = father[u][i];
    if(u == v) return u;
    for(int i = c; i >= 0; i--)
        if(father[u][i] != father[v][i]) 
            u = father[u][i], v = father[v][i];
    return father[u][0];
}

int main() {
    cin >> n >> q;
    for(int i = 0; i < n - 1; i++) {
        cin >> a >> b;
        father[b][0] = a;
        g[a].push_back(b);
    }
    while(n >>= 1) c++;
    dfs(1, 0);
    init(n);
    while(q--){
        cin >> a >> b;
        cout << lca(a, b) << endl;
    }
}