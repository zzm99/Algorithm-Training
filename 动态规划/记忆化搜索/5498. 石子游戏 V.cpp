class Solution {
public:
    int64_t dp[501][501]; // 记忆化数组，用于避免重复计算
    int64_t sum[501];
    
    int64_t dfs(int L, int R) {
        if(dp[L][R] != -1) { //已经计算过该子问题了，直接范围答案
            return dp[L][R];
        }
        if(L == R) { // 终止条件，直接获得答案
            dp[L][R] = 0;
        } else {
            //递进阶段，根据题意，求解最大值；
            int64_t val = 0;
            for(int i = L; i< R; i++) {
                int64_t s1 = sum[i] - sum[L-1];
                int64_t s2 = sum[R] - sum[i];
                
                if(s1 < s2) { // 根据题意，只能取后半段
                    val = max(val, s1 + dfs(L, i));
                } else if(s1 > s2){ // 根据题意，只能取前半段
                    val = max(val, s2 + dfs(i+1, R));
                } else { // 相等时，可任意选择~
                    val = max(dfs(L, i), dfs(i+1, R)) + s1;
                }
            }
            //回归阶段，更新答案
            dp[L][R] = val;
        }
        return dp[L][R];
    }
    
    int stoneGameV(vector<int>& stoneValue) {
        memset(dp, -1, sizeof(dp));
        
        //出来一下前缀和
        sum[0] = 0;
        for(int i = 0; i < stoneValue.size(); i++) {
            sum[i+1] = sum[i] + stoneValue[i];
        }
        
        return dfs(1, stoneValue.size());    
    }
};