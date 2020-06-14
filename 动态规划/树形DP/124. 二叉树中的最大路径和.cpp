class Solution {
public:
    int result;

    int maxPathSum(TreeNode* root) {
        if(!root) return 0;
        result = root->val;
        dfs(root);
        return result;    
    }

    int dfs(TreeNode* root){
        if(!root) return 0;
        int left = max(dfs(root->left), 0);
        int right = max(dfs(root->right), 0);
        result = max(root->val+left+right, result);
        return root->val + max(0, max(left, right));
    }
};
