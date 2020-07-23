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
    vector<TreeNode*> helper(int l, int r){
        vector<TreeNode*> ans;
        if(l > r) {
            ans.push_back(NULL);
            return ans;
        }
        for(int i=l; i<= r; i++){
            vector<TreeNode*> leftnode = helper(l, i-1);
            vector<TreeNode*> rightnode = helper(i+1, r);
            for(auto a: leftnode){
                for(auto b: rightnode){
                    TreeNode* t = new TreeNode(i);
                    t->left = a;
                    t->right = b;
                    ans.push_back(t);
                }
            }
        }
        return ans;
    }
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> ret;
        if(n!=0) return helper(1, n);
        return ret;
    }
};