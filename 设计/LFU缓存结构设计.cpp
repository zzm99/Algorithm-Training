#include <unordered_map>

struct Node {
    int key, value;
    int frequency, visit_time;
    Node() {}
    Node(int k, int v, int f, int t):key(k), value(v), frequency(f), visit_time(t){}
    bool operator <(const Node& node) const {
        if(this->frequency == node.frequency) {
            return this->visit_time < node.visit_time;
        } else {
            return this->frequency < node.frequency;
        }
    }
};

class Solution {
public:
    int sys_time;
    int capacity;
    set<Node> sorted_tree;
    unordered_map<int, Node> cache;
    void init(int _capacity) {
        capacity = _capacity;
        sys_time = 0;
    }
    int get(int key) {
        sys_time++;
        if(capacity == 0) return -1;
        auto it = cache.find(key);
        if(it == cache.end()) return -1;
        Node node = it->second;
        sorted_tree.erase(node);
        node.visit_time = sys_time;
        node.frequency ++;
        cache[key] = node;
        sorted_tree.insert(node);
        return node.value;
    }
    void set(int key, int value) {
        sys_time++;
        if(capacity == 0) return;
        auto it = cache.find(key);
        if(it == cache.end()) {
            if(cache.size() == capacity) {
                auto delNode = sorted_tree.begin();
                cache.erase(delNode->key);
                sorted_tree.erase(delNode);
            }
            Node newNode(key, value, 1, sys_time);
            cache[key] = newNode;
            sorted_tree.insert(newNode);
        } else {
            Node node = it->second;
            sorted_tree.erase(node);
            node.value = value;
            node.frequency++;
            node.visit_time = sys_time;
            cache[key] = node;
            sorted_tree.insert(node);
        }
    }
    vector<int> LFU(vector<vector<int> >& operators, int k) {
        // write code here
        vector<int> ans;
        init(k);
        for(auto& op: operators) {
            int operate = op[0];
            if(operate == 1) {
                set(op[1], op[2]);
            } else if(operate == 2) {
                ans.push_back(get(op[1]));
            } else {
                continue;
            }
        }
        return ans;
    }
};