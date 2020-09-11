class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> v;
        helper(candidates, target, 0, v);
        return res;
    }
private:
    vector<vector<int> > res;
    void helper(vector<int>& candidates, int target, int start, vector<int>& now) {
        if (target == 0) {
            res.emplace_back(now);
            return;
        }
        for (int i = start; i < candidates.size(); ++i) {
            if (target - candidates[i] < 0) break; // 无解
            if (i > start && candidates[i] == candidates[i-1]) continue; // 相同层数相同数字只用一次
            now.emplace_back(candidates[i]);
            helper(candidates, target-candidates[i], i+1, now);
            now.pop_back();
        }
        return;
    }
};
