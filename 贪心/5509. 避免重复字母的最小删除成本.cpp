class Solution {
public:
    int minCost(string s, vector<int>& cost) {
        int ans = 0;
        for(int i = 0;i<s.length();){
            int j = i;
            int sum = 0;
            int maxV = INT_MIN;
            while(j<s.length()&&s[j]==s[i]){
                sum+=cost[j];
                maxV = max(maxV,cost[j]);
                j++;
            }
            if(j-i>1){
                ans+=(sum-maxV);
            }
            i = j;
        }
        return ans;
    }
};
