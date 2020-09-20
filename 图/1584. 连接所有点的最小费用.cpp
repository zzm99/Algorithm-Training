class Solution {
public:
    vector<int> parent;
    int count = 0;

    struct Edge {
        int a, b, w;
        bool operator<(const Edge& e) const {
            return w < e.w;
        }
    };

    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        if(n <= 1) return 0;
        vector<Edge> connections;
        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++) {
                connections.push_back({i, j, abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1])});
            }
        }
        return miniumCost(n, connections);
    }
    
    int miniumCost(int n, vector<Edge>& connections) {
        parent = vector<int>(n, 0);
        for(int i=0; i<n; i++) {
            parent[i] = i;
        }
        sort(connections.begin(), connections.end());
        int res = 0;
        for(Edge& con: connections) {
            int pa = find(con.a);
            int pb = find(con.b);
            if(pa != pb) {
                uni(con.a, con.b);
                res += con.w;
            }
            if(count == n-1) return res;
        }
        return -1;
    }
    int find(int a) {
        if(parent[a] == a) return a;
        parent[a] = find(parent[a]);
        return parent[a];
    }
    void uni(int a, int b) {
        int pa = find(a);
        int pb = find(b);
        if(pa == pb) return;
        parent[pa] = pb;
        count++;
    }
};