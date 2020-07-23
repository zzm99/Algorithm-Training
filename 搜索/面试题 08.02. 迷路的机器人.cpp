class Solution {
public:
    bool dfs(vector<vector<int>>& g, int x, int y, vector<vector<int>>& p) {
        int m = g.size(), n = g[0].size();
        if(g[x][y] == 1) return false;
        if(x == m-1 && y == n-1) {
            p.push_back({x, y});
            return true;
        }
        p.push_back({x, y});
        if(x + 1 < m && dfs(g, x+1, y, p)) return true;
        if(y + 1 < n && dfs(g, x, y+1, p)) return true;
        p.pop_back();
        g[x][y] = 1;
        return false;
    }
    vector<vector<int>> pathWithObstacles(vector<vector<int>>& obstacleGrid) {
        vector<vector<int>> p;
        dfs(obstacleGrid, 0, 0, p);
        return p;
    }
};