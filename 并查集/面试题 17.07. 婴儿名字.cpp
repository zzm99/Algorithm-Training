class Solution {
public:
    unordered_map<string, string> parent, real;
    unordered_map<string, int> fre;
    
    string find_(string x) {
        return parent[x] == "" ? x : find_(parent[x]);
    }
    
    void union_(string x, string y) {
        string px = find_(x), py = find_(y);
        if(px == py) return;
        parent[py] = px;
        fre[px] += fre[py];
    }
    
    vector<string> trulyMostPopular(vector<string>& names, vector<string>& synonyms) {
        for(auto& it : names) {
            int pos = it.find("(");
            fre[it.substr(0, pos)] = stoi(it.substr(pos+1, it.size()-pos-1));
        }
        for(auto& it : synonyms) {
            int pos = it.find(",");
            union_(it.substr(1, pos-1), it. substr(pos+1, it.size()-2-pos));
        }
        vector<string> ret;
        for(auto& it: names) {
            string s = it.substr(0, it.find("(")), fa = find_(s);
            real[fa] = min(s, real[fa] == "" ? s: real[fa]);
        }
        for (auto& it : real)
            ret.push_back(it.second + "("+to_string(fre[find_(it.first)])+")");
        return ret;
    }
};