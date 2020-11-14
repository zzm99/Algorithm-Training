class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ret;
        deque<int> curmax;
        for(int i=0; i<nums.size(); i++) {
            while(!curmax.empty() && nums[curmax.back()] < nums[i]) {
                curmax.pop_back();
            }
            curmax.push_back(i);
            while(i-curmax.front()+1 > k) curmax.pop_front();
            if(i >= k-1) ret.push_back(nums[curmax.front()]);
        }
        return ret;
    }
};