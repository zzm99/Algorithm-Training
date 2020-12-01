class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int size = nums.size();      
        vector<int> fl(size) , fr(size);
        for(int i = 0 ; i < size ; i++){
            fl[i] = 1;
            for(int j = 0 ; j < i ; j++){
                if(nums[i] > nums[j])
                    fl[i] = max(fl[i] , fl[j] + 1);
            }
        }
        for(int i = size - 1; i >= 0 ; i--){
            fr[i] = 1;
            for(int j = size - 1 ; j > i ; j--){
                if(nums[i] > nums[j])
                    fr[i] = max(fr[i] , fr[j] + 1);
            }
        }

        int res = 0;
        for(int i = 0 ; i < size ; i++)
            if(fl[i] > 1 && fr[i] > 1)
                res = max(res , fl[i] + fr[i] - 1);
        return size - res;
    }
};

// 左右上升子序列的最长长度