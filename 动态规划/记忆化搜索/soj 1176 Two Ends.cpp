#include <iostream>
#include <vector>
using namespace std;

int dfs(int l, int r, vector<vector<int>>& dp, vector<vector<bool>>& cal, vector<int>& ans) {
    if(l > r) return 0;
    if(cal[l][r]) return dp[l][r];
    cal[l][r] = true;
    dp[l][r] = 0;
    dp[l][r] = max(dp[l][r], ans[l+1]>=ans[r] ? ans[l]-ans[l+1]+dfs(l+2, r, dp, cal, ans) : ans[l]-ans[r]+dfs(l+1, r-1, dp, cal, ans));;
    dp[l][r] = max(dp[l][r], ans[l]>=ans[r-1] ? ans[r]-ans[l]+dfs(l+1, r-1, dp, cal, ans) : ans[r]-ans[r-1]+dfs(l, r-2, dp, cal, ans));
    return dp[l][r];
}

int main() {
    int n;
    int t = 1;
    while(cin >> n) {
        if(n == 0) break;
        vector<int> ans(n);
        for(int i=0; i<n; i++) cin>>ans[i];
        vector<vector<int>> dp(n, vector<int>(n));
        vector<vector<bool>> cal(n, vector<bool>(n));
        int res = dfs(0, n-1, dp, cal, ans);
        cout << "In game " << t << ", the greedy strategy might lose by as many as "
            << res << " points." << endl;
        t++;
    }
    return 0;
}