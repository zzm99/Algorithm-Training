class Solution {
public:
    vector<string> printKMoves(int K) {
        int dir[2][4] = {{0,1,0,-1}, {1,0,-1,0}};
        char cc[4] = {'R', 'D', 'L', 'U'};
        map<pair<int, int>, char> m;
        int dd = 0, x = 0, y = 0, l = 0, r = 0, u = 0, d = 0;
        while(K--) {
            if(!m.count({x, y}) || m[{x, y}] == '_') {
                m[{x, y}] = 'X';
                dd = (dd+1) % 4;
                x += dir[0][dd];
                y += dir[1][dd];
            } else {
                m[{x, y}] = '_';
                dd = (dd-1) % 4;
                if(dd<0) dd += 4;
                x += dir[0][dd];
                y += dir[1][dd];    
            }
            l = min(l, y);
            r = max(r, y);
            u = min(u, x);
            d = max(d, x);
        }
        vector<string> ans = vector<string>(d-u+1, string(r-l+1, '_'));
        for(auto x : m) ans[x.first.first-u][x.first.second-l] = x.second;
        ans[x-u][y-l] = cc[dd];
        return ans;
    }
};