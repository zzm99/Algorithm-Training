class TreeAncestor {
public:
    vector<int> dep;
    vector<int> f[20];
    vector<vector<int>> G;
    void DFS(int u){
        for(int i = 1; i < 20; i += 1) f[i][u] = f[i - 1][f[i - 1][u]];
        for(int v : G[u]){
            dep[v] = dep[u] + 1;
            f[0][v] = u;
            DFS(v);
        }
    }
    TreeAncestor(int n, vector<int>& parent) {
        G.resize(n);
        dep.resize(n);
        for(int i = 0; i < 20; i += 1) f[i].resize(n);
        for(int i = 1; i < n; i += 1) G[parent[i]].push_back(i);
        DFS(0);
    }
    
    int getKthAncestor(int node, int k) {
        if(dep[node] < k) return -1;
        for(int i = 19; ~i; i -= 1)
            if(k >= (1 << i)){
                k -= 1 << i;
                node = f[i][node];
            }
        return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */