class Solution {
public:
    bool check(vector<int> &a) {
        sort(a.begin(), a.end());
        int p = -100000, q = -10000;
        for (int i = 0; i < a.size(); i++) {
            if (a[i] - p <= 60) return true;
            p = q;
            q = a[i];
        }
        return false;
    }
    vector<string> alertNames(vector<string>& keyName, vector<string>& keyTime) {
        map<string, vector<int>> mp;
        for (int i = 0; i < keyName.size(); i++) {
            auto s = keyTime[i];
            int p = (s[0] - '0') * 10 + (s[1] - '0');
            int q = (s[3] - '0') * 10 + (s[4] - '0');
            p = p * 60 + q;
            mp[keyName[i]].push_back(p);
        }
        vector<string> ans;
        for (auto &x : mp) {
            if (check(x.second)) {
                ans.push_back(x.first);
            }
        } 
        return ans;
    }
};