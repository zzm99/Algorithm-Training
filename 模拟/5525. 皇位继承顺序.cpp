class ThroneInheritance {
public:
    string kingName;
    unordered_map<string,vector<string>> sons;
    unordered_set<string> dead;
    ThroneInheritance(string _kingName) {
        kingName=_kingName;
    }    
    void birth(string parentName, string childName) {
        sons[parentName].push_back(childName);
    }
    
    void death(string name) {
        dead.insert(name);
    }
    
    vector<string> getInheritanceOrder() {
        vector<string> ans;
        dfs(kingName,ans);
        return ans;
    }
    void dfs(string &name,vector<string> &ans){
        if(dead.find(name)==dead.end())
            ans.push_back(name);
        for(string &s:sons[name]){
            dfs(s,ans);
        }
    }
};

/**
 * Your ThroneInheritance object will be instantiated and called as such:
 * ThroneInheritance* obj = new ThroneInheritance(kingName);
 * obj->birth(parentName,childName);
 * obj->death(name);
 * vector<string> param_3 = obj->getInheritanceOrder();
 */
