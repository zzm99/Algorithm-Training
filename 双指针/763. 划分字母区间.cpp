class Solution {
public:
    vector<int> partitionLabels(string S) {
        int last[26];
        for(int i=0; i<S.size(); i++) {
            last[S[i]-'a'] = i;
        }
        vector<int> res;
        int start = 0, end = 0;
        for(int i=0; i<S.size(); i++) {
            end = max(end, last[S[i]-'a']);
            if(i == end) {
                res.push_back(end-start+1);
                start = end+1;
            }
        }
        return res;
    }
};