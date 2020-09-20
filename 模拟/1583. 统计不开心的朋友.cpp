class Solution {
public:
    int unhappyFriends(int n, vector<vector<int>>& preferences, vector<vector<int>>& pairs) {
        unordered_map<int,unordered_set<int>> hashmap;
        for(auto i:pairs){
            for(auto j:preferences[i[0]]){
                if(j==i[1])break;
                hashmap[i[0]].insert(j);
            }
            for(auto j:preferences[i[1]]){
                if(j==i[0])break;
                hashmap[i[1]].insert(j);
            }
        }
        int ans=0;
        for(auto it = hashmap.begin();it!=hashmap.end();++it){
            for(auto i:it->second){
                if(hashmap.find(i)!=hashmap.end()){
                    if(hashmap[i].count(it->first)){
                        ans++;
                        break;
                    }
                }               
            }
        }
        return ans;
    }
};
