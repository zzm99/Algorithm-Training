#define maxn 50005
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
#define solve 1, cnt, 1 
const int mm = maxn * 4;

class Solution {
public:
    static const int mod = 1e9 + 7;
    int L[maxn], R[maxn], cnt;    
    vector<int> G[maxn];
    int sum[mm], add[mm];
    
    void dfs(int u) {
        ++ cnt; 
        L[u] = cnt;
        for (int v: G[u]) {
            dfs(v);
        }
        R[u] = cnt;
    }
    
    void build() {
        cnt = 0;
        memset(L, 0, sizeof(L));
        memset(R, 0, sizeof(R));
        memset(sum, 0, sizeof(sum));
        memset(add, 0, sizeof(add));
    }
    
    void push_up(int rt) {
        sum[rt] = sum[rt * 2] % mod + sum[rt * 2 + 1] % mod;
    }
    
    void push_down(int rt, int m) {
        if (add[rt] != 0) {
            add[rt << 1] = add[rt << 1] % mod + add[rt] % mod;
            add[rt << 1 | 1] = add[rt << 1 | 1] % mod + add[rt] % mod;
            sum[rt << 1] = sum[rt << 1] % mod + add[rt] * (m - (m / 2)) % mod;
            sum[rt << 1 | 1] = sum[rt << 1 | 1] % mod + add[rt] * (m / 2) % mod;
            add[rt] = 0;
        }
    }
    
    void update_single(int p, int val, int l, int r, int rt) {
        if (l == r) {
            sum[rt] = sum[rt] % mod + val % mod;
            return;   
        }
        push_down(rt, r - l + 1);
        int m = (l + r) >> 1;
        if (p <= m) {
            update_single(p, val, lson);
        }
        else {
            update_single(p, val, rson);
        }
        push_up(rt);
    }
    
    void update_range(int L, int R, int c, int l, int r, int rt) {
        if (L <= l && r <= R) {
            add[rt] = add[rt] % mod + c % mod;
            sum[rt] = sum[rt] % mod + c * (r - l + 1) % mod; 
            return;
        }
        push_down(rt, r - l + 1);
        int m = (l + r) / 2;
        if (L <= m) {
            update_range(L, R, c, lson);
        }
        if (m < R) {
            update_range(L, R, c, rson);
        }
        push_up(rt);
    }
    
    long long query(int L, int R, int l, int r, int rt) {
        if (L <= l && r <= R) {
            return sum[rt];
        }
        push_down(rt, r - l + 1);
        int m = (l + r) >> 1;
        long long ret = 0;
        if (L <= m) {
            ret += query(L, R, lson);
        }
        if (m < R) {
            ret += query(L, R, rson);
        }
        return ret;
    }
    
    vector<int> bonus(int n, vector<vector<int>>& leadership, vector<vector<int>>& operations) {
        build();
        for (auto l: leadership) {
            G[l[0]].push_back(l[1]);
        }
        dfs(1);
        vector<int> ans;
        for (auto op: operations) {
            switch (op[0]) {
                case 1:
                    update_single(L[op[1]], op[2], solve);
                    break;
                case 2:    
                    update_range(L[op[1]], R[op[1]], op[2], solve);
                    break;
                case 3:
                    long long cur = query(L[op[1]], R[op[1]], solve) % mod;    
                    ans.push_back((int)cur);
                    break;
            }
        }
        return ans;
    }
};
