class Solution {
public:
    int numWays(string s) {
        long long count1 = 0, n = s.size();
        unordered_map<long long, long long> mp; //存储1的位置
        for(int i = 0; i < n; i++) 
            if(s[i] == '1'){
                count1++; //统计1 的个数
                mp[count1] = i;
            }
        if(count1 == 0) return ((n - 1) * (n - 2) / 2) % 1000000007; //步骤3
        if(count1 % 3 != 0) return 0; //步骤1
        long long t = count1 / 3; //确立3等分1的个数
        return ((mp[t + 1] - mp[t]) * (mp[2 * t + 1] - mp[2 * t])) % 1000000007; //步骤4
    }
};
