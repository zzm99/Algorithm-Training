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
    TreeNode* build(queue<int>& d, queue<int>& v, int depth) {
        if(d.front() != depth) return NULL;
        TreeNode* root = new TreeNode(v.front());
        d.pop(); v.pop();
        root->left = build(d, v, depth+1);
        root->right = build(d, v, depth+1);
        return root;
    }
    TreeNode* recoverFromPreorder(string S) {
        int left = 0;
        queue<int> d, v;
        for(int i=0; i<S.size(); i++) {
            if(S[i] != '-') {
                d.push(i-left);
                left = i;
                while(i < S.size() && S[i] != '-') i++;
                v.push(stoi(S.substr(left, i-left)));
                left = i;
            }
        }
        return build(d, v, 0);
    }
};