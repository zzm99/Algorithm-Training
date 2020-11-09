class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int n = heights.size();
        priority_queue<int, vector<int>, greater<int>> q;
        int curb = 0;
        for(int i=1; i<heights.size(); i++) {
            int d = heights[i]-heights[i-1];
            if(d > 0) {
                q.push(d);
                if(q.size() > ladders) {
                    curb += q.top();
                    q.pop();
                }
                if(curb > bricks) {
                    return i-1;
                }
            }
        }
        return n-1;
    }
};