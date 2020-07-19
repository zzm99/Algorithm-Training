class Solution {
public:
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<vector<int>> v(n);
        for (auto &e : edges)
        {
            int x = e[0], y = e[1];
            v[x].push_back(y);
            v[y].push_back(x);
        }
        vector<vector<int>> s(n, vector<int>(26));
        
        vector<int> res(n);
        function<void(int,int)> dfs = [&](int x, int pre)
        {
            s[x][labels[x]-'a'] ++;
            for (auto y : v[x])
            {
                if (y == pre) continue;
                dfs(y, x);
                for (int i = 0; i < 26; ++i) s[x][i] += s[y][i];
            }
            res[x] = s[x][labels[x]-'a'];
        };
        
        dfs(0, -1);
        return res;
    }
};