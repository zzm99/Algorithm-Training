class Solution {
public:
    vector<int> getMaxMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<int> cur(m, 0);
        vector<int> ret(4, 0);
        int r1 = 0, c1 = 0;
        int curmax = INT_MIN;
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) cur[j] = 0;
            for(int j=i; j<n; j++) {
                int sum = 0;
                for(int k=0; k<m; k++) {
                    cur[k] += matrix[j][k];
                    if(sum > 0) sum += cur[k];
                    else {
                        r1 = i; c1 = k;
                        sum = cur[k];
                    }
                    if(sum > curmax) {
                        curmax = sum;
                        ret = {r1, c1, j, k};
                    }
                }
            }
        }

        return ret;
    }
};