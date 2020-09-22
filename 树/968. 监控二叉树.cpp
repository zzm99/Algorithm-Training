/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    //0:待覆盖
    //1:已覆盖
    //2:已安装相机
    int res;
    int minCameraCover(TreeNode* root) {
        res = 0;
        if(dfs(root) == 0) res++;
        return res;
    }
    int dfs(TreeNode* r) {
        if(r == NULL) return 1;
        int left = dfs(r->left);
        int right = dfs(r->right);
        if(left == 0 || right == 0) {
            res++;
            return 2;
        } else if(left == 1 && right == 1) {
            return 0;
        } else if(left + right >= 3) {
            return 1;
        }
        return -1;  
    }
};
