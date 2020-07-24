class Solution {
public:
    vector<int> missingTwo(vector<int>& nums) {
        int n = nums.size() + 2;
        long sum = 0;
        for(auto& x: nums) sum += x;
        int sumTwo = n*(n+1)/2 - sum, limits = sumTwo/2;
        sum = 0;
        for(auto& x: nums) {
            if(x <= limits) sum += x;
        }
        int one = limits*(limits+1)/2 - sum;
        return {one, sumTwo-one};
    }
};

class Solution {
public:
    vector<int> missingTwo(vector<int>& nums) {
        int ans = 0, n = nums.size();
        for (int i = 1; i <= n + 2; i ++) 
            ans ^= i;
        for (auto x: nums)
            ans ^= x;    // ans = one ^ two

        int one = 0;
        int diff = ans & -ans; // get lowbit
        
        for (int i = 1; i <= n + 2; i ++)
            if (diff & i) one ^= i; 
        for (auto x: nums)
            if (diff & x) one ^= x;  // one = one
        
        return {one, one ^ ans};
    }
};

class Solution {
public:
    vector<int> missingTwo(vector<int>& nums) {
        for (int i = 0; i < 3; i ++) nums.push_back(-1);

        for (int i = 0; i < nums.size(); i ++)
            while (i != nums[i] && nums[i] != -1)
                swap(nums[i], nums[nums[i]]);
        
        vector<int> ans;
        for (int i = 1; i < nums.size(); i ++) 
            if (nums[i] == -1) ans.push_back(i);
        return ans; 
    }
};
