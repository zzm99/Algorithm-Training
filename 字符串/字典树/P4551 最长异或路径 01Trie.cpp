#include <bits/stdc++.h>
using namespace std;

const int N = 100010;

int cnt, head[N];

struct edge {
    int nxt, to, w;
}e[N << 1];

void add_edge (int from, int to, int val) {
    e[++cnt].nxt = head[from];
    e[cnt].to = to;
    e[cnt].w = val;
    head[from] = cnt;
}

void add_len (int u, int v, int w) {
    add_edge (u, v, w);
    add_edge (v, u, w);
}

int n, u, v, w, sumx[N];

void get_sumx (int u, int fa) {
    for (int i = head[u]; i; i = e[i].nxt) {
        int v = e[i].to;
        if (v != fa) {
            sumx[v] = sumx[u] ^ e[i].w;
            get_sumx (v, u);
        }
    }
}

int ch[N * 31][2], max_size;

void insert (int val) {
    int now = 0;
    for (int i = 30, to = 0; i >= 0; --i) {
        to = ((val & (1 << i)) != 0); //如果 val 第 i 位上为 1
        if (!ch[now][to]) {
            ch[now][to] = ++max_size;
        }
        now = ch[now][to];
    }
}

int get_ans (int val) {
    int now = 0, ans = val;
    for (int i = 30; i >= 0; --i) {
        if (ans & (1 << i)) {
            //这一位为1 -> 向0走
            if (ch[now][0] != 0) {
                now = ch[now][0];
            } else {
                val ^= (1 << i);
                now = ch[now][1];
            }
        } else {
            //为0 -> 向1走
            if (ch[now][1] != 0) {
                val ^= (1 << i);
                now = ch[now][1];
            } else {
                now = ch[now][0];
            }
        }
    }
    return max (val, ans);
}

int main () {
    cin >> n;
    for (int i = 1; i <= n - 1; ++i) {
        cin >> u >> v >> w;
        add_len (u, v, w);
    }
    get_sumx (1, 0);
    for (int i = 1; i <= n; ++i) {
        insert (sumx[i]);
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        ans = max (ans, get_ans (sumx[i])); //求sumx与其他数的最大异或
    }
    cout << ans << endl;
}