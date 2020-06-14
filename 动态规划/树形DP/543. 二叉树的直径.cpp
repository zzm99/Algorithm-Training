class Solution {
public:
    int sum = 0;
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        dfs(root);
        return sum;
    }
    int dfs(TreeNode* root){
        if(!root) return 0;
        int l = root->left?dfs(root->left)+1:0, r = root->right?dfs(root->right)+1:0;
        sum = max(l+r, sum);
        return max(l, r);
    }
};