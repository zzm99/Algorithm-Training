class StackOfPlates {
private:
    vector<vector<int>> ss;
    int cap;
public:
    StackOfPlates(int _cap) : cap(_cap) {
        ss.push_back(vector<int>());
    }
    
    void push(int val) {
        if (cap > 0) {
            if (!ss.empty() && ss.back().size() < cap)
                ss.back().push_back(val);
            else{
                ss.push_back(vector<int>());
                ss.back().push_back(val);
            }
        }
    }
    
    int pop() {
        if (cap > 0) {
            if (ss.empty() || (ss.size() == 1 && ss.back().empty()))
                return -1;
            else{
                int val = ss.back().back();
                ss.back().pop_back();
                if (ss.back().empty())
                    ss.pop_back();
                return val;
            }
        }
        return -1;
    }
    
    int popAt(int index) {
        if (cap > 0) {
            if (ss.empty() || index >= ss.size() || (ss.size() == 1 && ss.back().empty()))
                return -1;
            else{
                int val = ss[index].back();
                ss[index].pop_back();
                if (ss[index].empty())
                    ss.erase(ss.begin() + index);
                return val;
            }
        }
        return -1;
    }
};
