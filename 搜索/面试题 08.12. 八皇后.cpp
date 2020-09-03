class Solution {
    vector<vector<string>> ret;
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> tmp;
        dfs(n, 0, tmp);
        return ret;
    }

    void dfs(int n, int level, vector<string>& tmp) {
        if (level >= n) {
            ret.push_back(tmp);
            return;
        }
        vector<int> vis(n, 1);
        for (int i = 0; i < tmp.size(); ++i) {
            int j = tmp[i].find("Q");
            vis[j] = 0;
            if (j - (level - i) >= 0) {
                vis[j - (level - i)] = 0;
            }
            if (j + (level - i) < n) {
                vis[j + (level - i)] = 0;
            }
        }
        
        for (int i = 0; i < n; ++i) {
            if (vis[i] == 1) {
                string curLevel(n, '.');
                tmp.push_back(curLevel.replace(i, 1, "Q"));
                dfs(n, level + 1, tmp);
                tmp.pop_back();
            }
        }
    }
};

////////////////

#include <stdio.h>
 
int n, allPlacedState, count;
 
void queen(int row, int ld, int rd)
{
    if (row != allPlacedState)
    {
        int pos = allPlacedState & ~(row | ld | rd);
        while (pos)
        {
            int p = pos & -pos;
            pos -= p;
            queen(row+p, (ld+p)<<1, (rd+p)>>1);
        }
    }
    else
    {
        count ++;
    }
}
 
int main()
{
    while (scanf("%d", &n) != EOF)
    {
        allPlacedState = (1<<n)-1;
        count = 0;
        queen(0, 0, 0);
        printf("%d\n", count);
    }
    return 0;
}
