class Solution {
public:
    int maxDistance(vector<int>& p, int m) {
        int n = p.size();
        sort(p.begin(), p.end());
        int L = 1, R = p.back()-p.front();
        
        const int INF = 1000000000;
        auto check = [&](int mid)
        {
            int last = -INF;
            int cnt = 0;
            for (int i = 0; i < n; ++i)
            {
                if (abs(p[i] - last) >= mid)
                {
                    cnt ++;
                    last = p[i];
                }
            }
            return cnt >= m;
        };
        
        int res = 0;
        while (L <= R)
        {
            int mid = (L+R)/2;
            if (check(mid))
            {
                res = mid;
                L = mid+1;
            }
            else
                R = mid-1;
        }
        return res;
    }
};