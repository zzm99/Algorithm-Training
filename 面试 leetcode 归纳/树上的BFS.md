# 树上的BFS

```cpp
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        if(!root) return ret;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            vector<int> out;
            int size = q.size();
            for(int i=0; i<size; i++){
                auto temp = q.front();
                q.pop();
                out.push_back(temp->val);
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
            ret.push_back(out);
        }
        return ret;
    }
};
```

```cpp
// 103. 二叉树的锯齿形层次遍历
// 给定一个二叉树，返回其节点值的锯齿形层次遍历。（即先从左往右，再从右往左进行下一层遍历，以此类推，层与层之间交替进行）。
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        if(!root) return ret;
        
        queue<TreeNode*> q;
        q.push(root);
        int flag = 0;
        while(!q.empty()){
            vector<int> out;
            int size = q.size();
            for(int i=0; i<size; i++){
                auto temp = q.front();
                q.pop();
                out.push_back(temp->val);
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
            if(flag % 2==1){
                reverse(out.begin(), out.end());
            }
            ret.push_back(out);
            flag++;
        }
        return ret;
    }
};
```

