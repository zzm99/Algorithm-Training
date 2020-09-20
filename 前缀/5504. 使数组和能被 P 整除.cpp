class Solution {
public:
    int minSubarray(vector<int>& a, int p) {
        int n = a.size();
        vector<int> s(n+1);
        for (int i = 1; i <= n; ++i) s[i] = (s[i-1]+a[i-1])%p;
        int sum = s[n];
        if (sum == 0) return 0;
        
        unordered_map<int, int> F;
        F[0] = 0;
        int res = n;
        for (int i = 1; i <= n; ++i)
        {
            if (F.count((s[i]-sum+p)%p)) res = min(res, i-F[(s[i]-sum+p)%p]);
            F[s[i]] = i;
        }
        if (res == n) res = -1;
        return res;
    }
};