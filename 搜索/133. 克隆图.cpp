/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node == NULL) return NULL;
        queue<Node*> q;
        q.push(node);
        unordered_map<Node*, Node*> mp;
        mp[node] = new Node(node->val);

        while(!q.empty()) {
            Node* cur = q.front(); q.pop();
            for(auto& ne: cur->neighbors) {
                if(mp.find(ne) == mp.end()) {
                    mp[ne] = new Node(ne->val);
                    q.push(ne);
                }
                mp[cur]->neighbors.push_back(mp[ne]);
            }
        }

        return mp[node];
    }
};