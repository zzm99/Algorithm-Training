class Solution {
public:
    int maxRepeating(string sequence, string word) {
        string res = "";
        int ans = 0;
        while(true){
            res += word;
            int ok = 0;
            for(int i = 0; i < sequence.size(); i += 1) if(sequence.substr(i, res.size()) == res) ok = 1;
            if(ok) ans += 1;
            else return ans;
        }
        return 0;
    }
};