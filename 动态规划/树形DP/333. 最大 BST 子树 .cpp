/*
Given a binary tree, find the largest subtree which is a Binary Search Tree (BST), where largest means subtree with largest number of nodes in it.

Note:
A subtree must include all of its descendants.
*/
class Solution {
public:
    vector<int> DFS(TreeNode* root, int& ans)
    {
        if(!root) return vector<int>{0, INT_MAX, INT_MIN};
        auto left=DFS(root->left, ans), right=DFS(root->right, ans);
        if(root->val > left[2] && root->val < right[1])
        {
            int Min =min(root->val, left[1]), Max =max(root->val, right[2]);
            ans = max(ans, left[0] + right[0] + 1);
            return vector<int>{left[0] +right[0] +1, Min , Max};
        }
        return vector<int>{0, INT_MIN, INT_MAX};
    }
    
    int largestBSTSubtree(TreeNode* root) {
        int ans = 0;
        DFS(root, ans);
        return ans;
    }
};