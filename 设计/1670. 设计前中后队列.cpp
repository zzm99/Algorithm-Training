class FrontMiddleBackQueue {
public:
    vector<int> v;
    FrontMiddleBackQueue() {

    }
    
    void pushFront(int val) {
        v.insert(v.begin(), val);
    }
    
    void pushMiddle(int val) {
        v.insert(v.begin() + v.size() / 2, val);
    }
    
    void pushBack(int val) {
        v.push_back(val);
    }
    
    int popFront() {
        if(v.empty()) return -1;
        int res = v[0];
        v.erase(v.begin());
        return res;
    }
    
    int popMiddle() {
        if(v.empty()) return -1;
        int res = v[(v.size() - 1) / 2];
        v.erase(v.begin() + (v.size() - 1) / 2);
        return res;
    }
    
    int popBack() {
        if(v.empty()) return -1;
        int res = v.back();
        v.pop_back();
        return res;
    }
};