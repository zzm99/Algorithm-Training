class Solution {
public:
    vector<vector<int>> multiSearch(string big, vector<string>& smalls) {
        if(smalls.empty() || smalls[0].empty()) return {{}};

        memset(son, 0, sizeof son);
        memset(key, 0, sizeof key);
        idx = 0;

        vector<vector<int>> res;
        for(auto w: smalls) insert(w);

        unordered_map<string, vector<int>> hash;
        for(int i=0; i<big.size(); i++) search(big, i, hash);

        for(auto w: smalls) {
            if(hash.count(w)) res.push_back(hash[w]);
            else res.push_back({});
        }

        return res;
    }
private:
    const static int N = 1e5 + 10;
    int son[N][26], idx;
    string key[N];

    void insert(string s) {
        int p = 0;
        for(int i=0; i<s.size(); i++) {
            int u = s[i]-'a';
            if(!son[p][u]) son[p][u] = ++idx;
            p = son[p][u];
        }
        key[p] = s;
    }

    void search(string s, int st, unordered_map<string, vector<int>> &hash) {
        int p = 0;
        for(int i=st; i<s.size(); i++) {
            int u = s[i]-'a';
            if(!son[p][u]) return;
            p = son[p][u];
            if(key[p] != "") hash[key[p]].push_back(st);
        }
    }
};