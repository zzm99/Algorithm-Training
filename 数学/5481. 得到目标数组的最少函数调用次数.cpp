class Solution {
public:
    int minOperations(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        int ret = 0;
        int maxn = 0;
        
        for(auto num: nums) {
            if(num == 0) continue;
            int tmp = num;
            int count = 0;
            while(tmp) {
                if(tmp % 2 == 1) tmp--, ret++;
                if(tmp == 0) break;
                tmp /= 2;
                count++;
            }
            maxn = max(maxn, count);
        }
        
        ret += maxn;
        return ret;
    }
};