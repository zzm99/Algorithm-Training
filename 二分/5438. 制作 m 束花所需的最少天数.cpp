typedef long long ll;

class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if (n / k < m)
            return -1;
        int l = 1, r = 1e9;
        auto check = [&](int x) {
            vector<bool> flower(n);
            for (int i = 0; i < n; ++i)
                if (bloomDay[i] <= x)
                    flower[i] = true;
            int bunch = 0, curr = 0;
            for (int i = 0; i < n; ++i) {
                if (flower[i])
                    curr++;
                else {
                    bunch += curr / k;
                    curr = 0;
                }
            }
            bunch += curr / k;
            return bunch;
        };
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (check(mid) < m)
                l = mid + 1;
            else
                r = mid - 1;
        }
        return l;
    }
};