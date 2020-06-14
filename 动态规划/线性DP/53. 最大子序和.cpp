class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ret = nums[0];
        int sum = 0;
        for(auto num: nums) {
            if(sum > 0) sum += num;
            else sum = num;
            ret = max(ret, sum);
        }
        return ret;
    }
};