class Solution {
public:
    int bestSeqAtIndex(vector<int>& height, vector<int>& weight) {
        vector<pair<int,int>> tmp;
        for(int i = 0; i < height.size(); i++) tmp.push_back({height[i], weight[i]});
        sort(tmp.begin(), tmp.end(), [](const pair<int,int> &a, const pair<int,int> &b) {
            return a.first == b.first ? a.second > b.second : a.first < b.first;
        });
        vector<int> dp; 
        for(const auto &[h, w]: tmp) { // 最长上升子序列的二分解法，重点关心dp最后一项的更新 前面的更新 无关紧要 修改了不影响正确答案
            auto p = lower_bound(dp.begin(), dp.end(), w);  
            if(p == dp.end()) dp.push_back(w);
            else *p = w;
        }
        return dp.size();
    }
};
