class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        int n = nums.size();
        vector<int> preOddSum(n+1); //奇数项前缀和
        vector<int> preEvenSum(n+1); //偶数项前缀和
        preOddSum[0] = 0, preEvenSum[0] = 0;
        
        for (int i = 1; i <= n; i++) {
            if (i % 2 == 1) {   // 注意，下标为奇数，是偶数项
                preOddSum[i] = preOddSum[i-1] + nums[i-1];
                preEvenSum[i] = preEvenSum[i-1];
            } else {
                preOddSum[i] = preOddSum[i-1];
                preEvenSum[i] = preEvenSum[i-1] + nums[i-1];
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int oddSum = 0, evenSum = 0;
            if (i % 2 == 0) {   // 删除奇数项
                oddSum = preOddSum[i] + preEvenSum[n] - preEvenSum[i];
                evenSum = preEvenSum[i] + preOddSum[n] - preOddSum[i] - nums[i];    // 后半部分的奇数项求和时，要减去当前项
            } else {
                oddSum = preOddSum[i] + preEvenSum[n] - preEvenSum[i] - nums[i];
                evenSum = preEvenSum[i] + preOddSum[n] - preOddSum[i];
            }
            if (oddSum == evenSum)  ans++;
        }
        return ans;
    }
};
