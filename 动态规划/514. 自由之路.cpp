class Solution {
public:
    vector<vector<int>> memo;

    int findRotateSteps(string ring, string key) {
        memo.assign(ring.size(), vector<int>(key.size(), -1));
        return dfs(ring, 0, key, 0) + key.size();
    }

    int dfs(string ring, int i, string key, int j) {
        if(j == key.size()) {
            return 0;
        }
        if(memo[i][j] != -1) {
            return memo[i][j];
        }
        int right_step;
        for(int p = 0; p < ring.size(); p++) {
            if(ring[(i+p) % ring.size()] == key[j]) {
                right_step = dfs(ring, (i+p)%ring.size(), key, j+1)+p;
                break;
            }
        }
        int left_step;
        for(int p = 0; p < ring.size(); p++) {
            if(i-p >= 0 && ring[i-p]==key[j]) {
                left_step = dfs(ring, i-p, key, j+1)+p;
                break;
            } else if(i-p < 0 && ring[ring.size()-abs(i-p)] == key[j]) {
                left_step = dfs(ring, ring.size()-abs(i-p), key, j+1)+p;
                break;
            }
        }
        memo[i][j] = min(left_step, right_step);
        return memo[i][j];
    }
};