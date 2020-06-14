class Solution {
public:
    vector<int> E[64];
    int used[64];
    int matched[64];

    bool dfs(int u) {
        for(int next: E[u]) {
            if(used[next]) continue;
            used[next] = true;
            if(matched[next] == -1 || dfs(matched[next])) {
                matched[next] = u;
                return true;
            }
        }
        return false;
    }

    int domino(int n, int m, vector<vector<int>>& broken) {
        vector<vector<int>> br(n, vector<int>(m));
        for(auto& b: broken) br[b[0]][b[1]] = 1;
        vector<int> start;
        int delta[] = {-1, 0, 1, 0, -1};
        for(int i=0; i<n; i++) {
            for(int j=i%2; j<m; j+=2) {
                if(br[i][j] == 1) continue;
                start.push_back(i*m+j);
                for(int k=0; k<4; k++) {
                    int y = i + delta[k];
                    int x = j + delta[k+1];
                    if(y == -1 || y == n || x == -1 || x == m || br[y][x] == 1) continue;
                    E[i*m+j].push_back(y*m+x);
                }
            }
        }
        memset(matched, -1, sizeof(matched));
        int ans = 0;
        for(int i: start) {
            memset(used, 0, sizeof(used));
            if(dfs(i)) ans++;
        }
        return ans;
    }
};