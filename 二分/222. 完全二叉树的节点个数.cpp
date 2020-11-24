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
    int getDepth(TreeNode* r){
        int d = 0;
        while(r != NULL){
            d++;
            r = r->left;
        }
        return d;
    }
    int countNodes(TreeNode* root) {
        /**
        完全二叉树的高度可以直接通过不断地访问左子树就可以获取
        判断左右子树的高度: 
        如果相等说明左子树是满二叉树, 然后进一步判断右子树的节点数(最后一层最后出现的节点必然在右子树中)
        如果不等说明右子树是深度小于左子树的满二叉树, 然后进一步判断左子树的节点数(最后一层最后出现的节点必然在左子树中)
        **/
        if(!root) return 0;
        int ld = getDepth(root->left);
        int rd = getDepth(root->right);
        if(ld == rd) return (1<<ld) + countNodes(root->right);
        else return (1<<rd) + countNodes(root->left);
    }
};