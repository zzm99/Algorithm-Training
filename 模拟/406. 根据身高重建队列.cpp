class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0] || (a[0] == b[0] && a[1] > b[1]);
        });
        int n = people.size();
        vector<vector<int>> ans(n);
        for(const vector<int>& person: people) {
            int spaces = person[1]+1;
            for(int i=0; i<n; i++) {
                if(ans[i].empty()) {
                    --spaces;
                    if(!spaces) {
                        ans[i] = person;
                        break;
                    }
                }
            }
        }
        return ans;
    }
};