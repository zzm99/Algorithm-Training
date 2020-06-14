class Solution {
public:
    int rob(TreeNode* root) {
        vector<int> ret = dfs(root);
        return max(ret[0], ret[1]);
    }
    vector<int> dfs(TreeNode* root){
        vector<int> ret(2);
        if(!root) return ret;
        vector<int> left = dfs(root->left);
        vector<int> right = dfs(root->right);
        ret[0] = max(left[0], left[1]) + max(right[0], right[1]);
        ret[1] = root->val + left[0] + right[0];
        return ret;
    }
};