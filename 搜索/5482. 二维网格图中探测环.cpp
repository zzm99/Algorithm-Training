class Solution {
public:
    int dx[4] = {0,0,1,-1};
    int dy[4] = {1,-1,0,0};
    
    bool dfs(vector<vector<char>>& grid, vector<vector<int>>& vis, int x, int y, int ox, int oy, char f, vector<vector<int>>& ttt) {
        if(vis[x][y] == 1 && grid[x][y] == f) return true;
        if(grid[x][y] != f) return false;
        
        vis[x][y] = 1;
        ttt[x][y] = 1;
        
        for(int k=0; k<4; k++) {
            int nx = x+dx[k], ny = y+dy[k];
            if(nx < 0 || ny < 0 || nx >= grid.size() || ny >= grid[0].size()) continue;
            if(nx == ox && ny == oy) continue; 
            if(dfs(grid, vis, nx, ny, x, y, f, ttt)) return true;
        }
        
        vis[x][y] = 0;
        return false;
    }
    
    bool containsCycle(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> vis(m, vector<int>(n));
        vector<vector<int>> ttt(m, vector<int>(n));
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(ttt[i][j] == 0) {
                    if(dfs(grid, vis, i, j, -1, -1, grid[i][j], ttt)) 
                        return true;
                }
            }
        }
        return false;
    }
};