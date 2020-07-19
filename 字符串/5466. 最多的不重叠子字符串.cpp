class Solution {
public:
    using pii = pair<int, int>;
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.size();
        const int INF = 1000000000;
        
        vector<vector<int>> pos(26);
        
        vector<int> L(26, INF), R(26, -INF);
        vector<int> cnt(26);
        for (int i = 0; i < n; ++i)
        {
            pos[s[i]-'a'].push_back(i);
            L[s[i]-'a'] = min(L[s[i]-'a'], i);
            R[s[i]-'a'] = max(R[s[i]-'a'], i);
            cnt[s[i]-'a'] ++;
        }
        
        vector<pii> H;
        for (int i = 0; i < 26; ++i)
        {
            if (cnt[i] == 0) continue;
            int x = L[i], y = R[i], tot = cnt[i];
            vector<int> u(26);
            u[i] = 1;
            while (y-x+1 != tot)
            {
                for (int j = 0; j < 26; ++j)
                {
                    if (!u[j] && cnt[j] != 0)
                    {
                        auto it = lower_bound(pos[j].begin(), pos[j].end(), x);
                        if (it != pos[j].end() && *it <= y)
                        {
                            u[j] = 1;
                            tot += cnt[j];
                            x = min(x, L[j]);
                            y = max(y, R[j]);
                        }
                    }
                }
            }
            H.push_back({x, y});
        }
        
        sort(H.begin(), H.end(), [](const pii &a, const pii &b)
             {
                 return abs(a.first-a.second) < abs(b.first-b.second);
             });
        
        vector<string> res;
        vector<int> ok(H.size());
        for (int i = 0; i < H.size(); ++i)
        {
            if (ok[i]) continue;
            auto [x, y] = H[i];
            for (int j = 0; j < H.size(); ++j)
            {
                auto [L, R] = H[j];
                if (L <= x && y <= R) ok[j] = 1;
            }
            res.push_back(s.substr(x, y-x+1));
        }
        return res;
    }
};