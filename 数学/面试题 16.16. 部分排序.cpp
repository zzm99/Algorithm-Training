class Solution {
public:
    vector<int> subSort(vector<int>& array) {
        if(array.empty()) return {-1,-1};
        int last = -1, first = -1, maxn = INT_MIN, minn = INT_MAX;
        int len = array.size();
        for(int i=0; i<len; i++) {
            if(array[i] < maxn) last = i;
            if(array[len-1-i] > minn) first = len-1-i;
            maxn = max(maxn, array[i]);
            minn = min(minn, array[len-1-i]);
        }
        return {first, last};
    }
};
