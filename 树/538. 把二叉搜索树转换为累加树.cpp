class Solution {
public:
    TreeNode* convertBST(TreeNode* root) {
        if(!root) return root;
        stack<TreeNode*> q;
        TreeNode* p = root;
        int sum = 0;
        while(!q.empty() || root){
            if(root){
                q.push(root);
                root = root->right;
            }else{
                TreeNode* cur = q.top(); q.pop();
                sum += cur->val;
                cur->val = sum;
                root = cur->left;
            }
        }
        return p;
    }
};