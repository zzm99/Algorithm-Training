class Solution {
public:
    int m;
    TreeNode* ans;
    void dfs(TreeNode* p) {
        if(!p || m < 1) return;
        dfs(p->left);
        if(m == 1) ans = p;
        if(--m > 0) dfs(p->right);
    }
    TreeNode* KthNode(TreeNode* pRoot, int k) {
        ans = NULL, m = k;
        dfs(pRoot);
        return ans;
    }
};