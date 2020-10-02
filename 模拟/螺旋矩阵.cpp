class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        vector<int> ret;
        if(matrix.empty()) return ret;
        int top = 0, bottom = matrix.size()-1;
        int left = 0, right = matrix[0].size()-1;
        while(top < (matrix.size()+1)/2 && left < (matrix[0].size()+1)/2) {
            for(int i=left; i<=right; i++) {
                ret.push_back(matrix[top][i]);
            }
            for(int i=top+1; i<=bottom; i++) {
                ret.push_back(matrix[i][right]);
            }
            for(int i=right-1; top != bottom && i >= left; i--) {
                ret.push_back(matrix[bottom][i]);
            }
            for(int i=bottom-1; left!=right && i >= top+1; i--) {
                ret.push_back(matrix[i][left]);
            }
            ++top, --bottom, ++left, --right;
        }
        
        return ret;
    }
};