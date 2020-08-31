class Solution {
public:
    void dfs(int n, int m, vector <vector <int>> &grid, vector <vector <bool>> &vis, int x, int y) {
        if (x < 0 || y < 0 || x >= n || y >= m) return ;
        if (vis[x][y]) return;
        if (grid[x][y] == 0) return ;
        vis[x][y] = 1;
        dfs(n, m, grid, vis, x + 1, y);
        dfs(n, m, grid, vis, x - 1, y);
        dfs(n, m, grid, vis, x, y - 1);
        dfs(n, m, grid, vis, x, y + 1);
    }
    bool check(int n, int m, vector <vector <int>> &grid) {
        int cnt = 0;
        vector <vector <bool>> vis;
        vis.resize(n);
        for (auto &line : vis) line.resize(m);
        for (int i = 0; i < n; ++ i)
                for (int j = 0; j < m; ++ j) vis[i][j] = 0;
        for (int i = 0; i < n; ++ i) 
            for (int j = 0; j < m; ++ j) {
                if (grid[i][j] == 0) continue;
                if (!vis[i][j]) {
                    dfs(n, m, grid, vis, i, j);
                    ++ cnt;
                    if (cnt >= 2) return true;
                }
            }
        if (cnt == 0) return true;
        return false;
    }
    int minDays(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        if (check(n, m, grid)) return 0;
        for (int i = 0; i < n; ++ i)
            for (int j = 0; j < m; ++ j) {
                if (grid[i][j] == 0) continue;
                grid[i][j] = 0;
                if(check(n, m, grid)) return 1;
                grid[i][j] = 1;
            }
        return 2;
    }
};