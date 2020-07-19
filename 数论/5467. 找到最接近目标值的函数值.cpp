class Solution {
public:
    int closestToTarget(vector<int>& arr, int target) {
        int ans = abs(arr[0] - target);
        vector<int> valid = {arr[0]};
        for (int num: arr) {
            vector<int> validNew = {num};
            ans = min(ans, abs(num - target));
            for (int prev: valid) {
                validNew.push_back(prev & num);
                ans = min(ans, abs((prev & num) - target));
            }
            validNew.erase(unique(validNew.begin(), validNew.end()), validNew.end());
            valid = validNew;
        }
        return ans;
    }
};
// 如果我们固定右端点 r，并且从大到小在 [0, r] 的区间内枚举左端点 l，那么这个按位与之和是单调递减的。