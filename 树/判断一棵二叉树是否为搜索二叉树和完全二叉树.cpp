/**
 * struct TreeNode {
 *	int val;
 *	struct TreeNode *left;
 *	struct TreeNode *right;
 * };
 */

class Solution {
public:
    int last=INT_MIN;
    bool IsSearch(TreeNode* root)
    {
       if(root){
            bool res=IsSearch(root->left);
            if(res==false) return res;
            if(last>root->val) return false;
            last=root->val;
            return IsSearch(root->right);
        }
        return true;
    }
    bool flag=false;
    bool IsComplete(TreeNode* root)
    {
      if(root){
            if(root->left==nullptr && root->right==nullptr) return true;
            if(root->left && root->right==nullptr){
                if(flag) return false;
                flag=true;
            }
            if(root->left==nullptr && root->right) return false;
            return IsComplete(root->left) && IsComplete(root->right);
        }
        return true;
    }
    vector<bool> judgeIt(TreeNode* root) {
        // write code here
        bool flag1=IsSearch(root);
        bool flag2=IsComplete(root);
        vector<bool> res;
        res.push_back(flag1);
        res.push_back(flag2);
        return res;
    }
};