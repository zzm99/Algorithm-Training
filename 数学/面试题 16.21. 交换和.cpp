class Solution {
public:
    vector<int> findSwapValues(vector<int>& array1, vector<int>& array2) {
        long sum1 = 0, sum2 = 0;
        sum1 = accumulate(array1.begin(), array1.end(), 0L);
        sum2 = accumulate(array2.begin(), array2.end(), 0L);
        long max_dis = (0L+INT_MAX-INT_MIN);
        int dis = abs(sum2-sum1);
        if(dis > 2*max_dis || (dis & 1)) return {};
        
        dis = dis/2;
        unordered_map<int, bool> umap;
        bool flag = sum1 > sum2;
        for(int i=0; i<array1.size(); i++) umap[array1[i]] = true;
        for(int i=0; i<array2.size(); i++) {
            int target = 0;
            if(flag) {
                target = 0L + array2[i] + dis;
            } else {
                target = 0L + array2[i] - dis;
            }
            if(target <= INT_MAX && target >= INT_MIN && umap.count(target)) 
                return {target, array2[i]};
        }
        return {};
    }
};