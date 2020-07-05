class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int> > left(n,vector<int>(m));
        int now = 0;
        for(int i=0;i<n;i++){
            now = 0;
            for(int j=0;j<m;j++){
                if(mat[i][j] == 1) now ++;
                else now = 0;
                left[i][j] = now;
            }
        }
        int ans = 0,minx;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                minx = 0x3f3f3f3f;
                for(int k=i;k>=0;k--){
                    minx = min(left[k][j],minx);
                    ans += minx;
                }
            }
        }
        return ans;
    }
};