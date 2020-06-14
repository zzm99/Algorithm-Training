# 树上的DFS

```cpp
// 113. 路径总和 II
// 给定一个二叉树和一个目标和，找到所有从根节点到叶子节点路径总和等于给定目标和的路径。

// 说明: 叶子节点是指没有子节点的节点。
class Solution {
public:
    void helper(TreeNode* root, int cur, vector<vector<int>>& ret, vector<int> c){
        if(!root) return;
        if(root->left == NULL && root->right == NULL){
            if(cur-root->val == 0){
                c.push_back(root->val); ret.push_back(c); return;
            }
        }
        c.push_back(root->val);
        if(root->left) helper(root->left, cur-root->val, ret, c);
        if(root->right) helper(root->right, cur-root->val, ret, c);
    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> ret;
        if(!root) return ret;
        vector<int> ord;
        helper(root, sum, ret, ord);
        return ret;
    }
};
```

```cpp
// 437. 路径总和 III
// 给定一个二叉树，它的每个结点都存放着一个整数值。

// 找出路径和等于给定数值的路径总数。

// 路径不需要从根节点开始，也不需要在叶子节点结束，但是路径方向必须是向下的（只能从父节点到子节点）。

// 二叉树不超过1000个节点，且节点数值范围是 [-1000000,1000000] 的整数。
class Solution {
public:
    int pathSum(TreeNode* root, int sum) {
        unordered_map<int, int> cnt;
        cnt[0] = 1;
        return helper(root, sum, cnt, 0);
    }
    int helper(TreeNode* root, int sum, unordered_map<int,int>& cnt, int pre){
        if(!root) return 0;
        pre += root->val;
        int ans = cnt[pre-sum];
        ++cnt[pre];
        ans += helper(root->left, sum, cnt, pre) + helper(root->right, sum, cnt, pre);
        --cnt[pre];
        return ans;
    }
};
```