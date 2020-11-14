class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        if(n == 1) return nums[0];
        int p = nums[0];
        int maxp = nums[0];
        int minp = nums[0];
        for(int i=1; i<n; i++){
            int t = maxp;
            maxp = max({maxp*nums[i], nums[i], minp*nums[i]});
            minp = min({t*nums[i], nums[i], minp*nums[i]});
            p = max(maxp, p);
        }
        return p;
    }
};