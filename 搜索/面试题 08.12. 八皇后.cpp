class Solution {
    vector<vector<string>> ret;
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> tmp;
        dfs(n, 0, tmp);
        return ret;
    }

    void dfs(int n, int level, vector<string>& tmp) {
        if (level >= n) {
            ret.push_back(tmp);
            return;
        }
        vector<int> vis(n, 1);
        for (int i = 0; i < tmp.size(); ++i) {
            int j = tmp[i].find("Q");
            vis[j] = 0;
            if (j - (level - i) >= 0) {
                vis[j - (level - i)] = 0;
            }
            if (j + (level - i) < n) {
                vis[j + (level - i)] = 0;
            }
        }
        
        for (int i = 0; i < n; ++i) {
            if (vis[i] == 1) {
                string curLevel(n, '.');
                tmp.push_back(curLevel.replace(i, 1, "Q"));
                dfs(n, level + 1, tmp);
                tmp.pop_back();
            }
        }
    }
};
