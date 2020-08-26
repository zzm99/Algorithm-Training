// 找欧拉路径 Hierholzer 算法
class Solution {
public:
    unordered_map<string, priority_queue<string, vector<string>, std::greater<string>>> vec;

    vector<string> stk;

    void dfs(const string& curr) {
        while (vec.count(curr) && vec[curr].size() > 0) {
            string tmp = vec[curr].top();
            vec[curr].pop();
            dfs(move(tmp));
        }
        stk.emplace_back(curr);
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for (auto& it : tickets) {
            vec[it[0]].emplace(it[1]);
        }
        dfs("JFK");

        reverse(stk.begin(), stk.end());
        return stk;
    }
};

//////////////

class Solution {
public:
    unordered_map<string, int> mp;
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        vector<string> airpots;
        for(auto v: tickets){
            string c1 = v[0], c2 = v[1];
            if(find(airpots.begin(), airpots.end(), c1) == airpots.end()) airpots.push_back(c1);
            if(find(airpots.begin(), airpots.end(), c2) == airpots.end()) airpots.push_back(c2);
        }
        sort(airpots.begin(), airpots.end());
        int n = airpots.size();
        for(int i=0; i<n; i++){
            mp[airpots[i]] = i;
        }
        vector<vector<int>> gh(n, vector<int>(n));
        for(auto v: tickets){
            int from = mp[v[0]], to = mp[v[1]];
            gh[from][to]++;
        }
        vector<string> ret;
        vector<string> cur;
        int curid = mp["JFK"];
        dfs(gh, ret, curid);
        reverse(ret.begin(), ret.end());
        return ret;
    }
    void dfs(vector<vector<int>>& gh, vector<string>& ret, int i){
        for (int j = 0; j < gh.size(); ++j) {
            if (gh[i][j] > 0) {
                --gh[i][j];
                dfs(gh, ret, j);
            }
        }
        for(auto m: mp)
            if(m.second == i){
                ret.push_back(m.first);
                break;
            }
    }
};