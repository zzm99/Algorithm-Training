class Solution {
public:
    int pileBox(vector<vector<int>>& box) {
        int n = box.size();
        vector<int> f(n + 1);
        sort(box.begin(), box.end(), [](vector<int> &a, vector<int> &b) {
            if (a[0] == b[0]) {
                if (a[1] == b[1]) return a[2] < b[2];
                return a[1] < b[1];
            }
            return a[0] < b[0];
        });
        int res = 0;
        for (int i = 1; i <= n; i ++) {
            f[i] = box[i - 1][2];
            res = max(res, f[i]);
            for (int j = 1; j < i; j ++) {
                if (box[i - 1][0] > box[j - 1][0] && box[i - 1][1] > box[j - 1][1] && box[i - 1][2] > box[j - 1][2]) {
                    f[i] = max(f[i], f[j] + box[i - 1][2]);
                    res = max(res, f[i]);
                }
            }
        }
        return res;
    }
};
