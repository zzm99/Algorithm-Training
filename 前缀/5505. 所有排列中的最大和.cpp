class Solution {
public:
    int maxSumRangeQuery(vector<int>& a, vector<vector<int>>& requests) {
        using ll = long long;
        int n = a.size();
        sort(a.begin(), a.end());
        vector<ll> s(n+5);
        for (auto &e : requests)
        {
            int x = e[0]+1, y = e[1]+1;
            s[x] += 1;
            s[y+1] -= 1;
        }
        for (int i = 1; i <= n; ++i) s[i] += s[i-1];
        sort(s.begin()+1, s.begin()+n+1);
        
        ll res = 0;
        for (int i = n; i >= 1; --i)
        {
            res += (ll)a[i-1] * s[i];
        }
        
        const int mod = 1000000007;
        
        res %= mod;
        return res;
    }
};