/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int ans;
    vector<int> dfs(TreeNode* root, int distance) {
		if (root->left == nullptr&&root->right == nullptr)
			return{ 1 };
		vector<int>v1, v2,v3;
		if (root->left)
		    v1 = dfs(root->left, distance);
		if (root->right)
			v2 = dfs(root->right, distance);
		for (int i : v1)
			for (int j : v2)
				if (i + j <= distance)
					ans++;
		for (int i : v1)
			v3.push_back(i + 1);
		for (int j : v2)
			v3.push_back(j + 1);
		return v3;
	}
    int countPairs(TreeNode* root, int distance) {
        ans = 0;
        dfs(root, distance);
        return ans;
    }
};