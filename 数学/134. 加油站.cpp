class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int res = 0;
        int minres = INT_MAX;
        int minindex = 0;
        for(int i=0; i<n; i++) {
            res += gas[i]-cost[i];
            if(res < minres) {
                minres = res;
                minindex = i;
            }
        }
        return res < 0 ? -1 : (minindex + 1) % n;
    }
};