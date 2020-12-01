class Solution {
public:
    int binarySearch(vector<int>& nums, int target, bool lower) {
        int left = 0, right = (int)nums.size()-1, ans = (int)nums.size();
        while(left <= right) {
            int mid = (left + right) / 2;
            if(nums[mid] > target || (lower && nums[mid] >= target)) {
                right = mid-1;
                ans = mid;
            } else {
                left = mid+1;
            }
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int leftIdx = binarySearch(nums, target, true);
        int rightIdx = binarySearch(nums, target, false)-1;
        if (leftIdx <= rightIdx && rightIdx < nums.size() && nums[leftIdx] == target && nums[rightIdx] == target) {
            return vector<int>{leftIdx, rightIdx};
        } 
        return vector<int>{-1, -1};
    }
};

/////

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res(2, -1);
        if(nums.empty()) return res;
        int n = nums.size(); 
        int l = 0, r = n-1;
        while(l < r){
            int m = l + (r-l)/2;
            if(nums[m] >= target) r = m;
            else l = m+1;
        }
        if(nums[l] != target) return res;
        res[0] = l;
        r = n;
        while(l < r){
            int m = l + (r-l)/2;
            if(nums[m] <= target) l = m+1;
            else r = m;
        }
        res[1] = l-1;
        return res;
    }
};