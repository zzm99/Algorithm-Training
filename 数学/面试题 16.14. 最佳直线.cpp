class Solution {
public:
    vector<int> bestLine(vector<vector<int>>& points) {
        map<vector<double>, int> hash;
        int n = points.size();
        for(int i=0; i<n-1; i++) {
            for(int j=i+1; j<n; j++) {
                double k, b;
                if(points[i][0] == points[j][0]) k = INT_MAX, b = points[i][0];
                else k = (points[i][1]-points[j][1])/(double)(points[i][0]-points[j][0]), b = points[j][1]-k*points[j][0];
                if(!hash.count({k, b})) hash[{k, b}] = i*n + j;
            }
        }
        int maxv = INT_MIN;
        vector<int> res;
        for(auto x : hash) {
            int t1 = x.second / n, t2 = x.second % n, cnt = 0;
            double k = x.first[0], b = x.first[1];
            for(int i=0; i<n; i++) {
                if(i != t1 && i != t2) {
                    if(k == INT_MAX && b == points[i][0]) cnt ++;
                    else if(fabs(k * points[i][0] + b-points[i][1]) < 1e-8) cnt ++;
                }
            }
            if(cnt > maxv) maxv = cnt, res = {t1, t2};
            else if(cnt == maxv) {
                if(t1 < res[0] || (t1 == res[0] && t2 < res[1])) res = {t1, t2};
            }
        }
        return res;
    }
};