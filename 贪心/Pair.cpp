#include <iostream>
#include <string.h>
#include <algorithm>
#include <vector>
#include <queue>
#define N 10005
// http://soj.acmm.club/show_problem.php?pid=1005&cid=2803
using namespace std;

int citynum, casenum;
bool visited[N];
int edgenum[N];

int main() {
    cin >> casenum;
    while (casenum > 0) {
        cin >> citynum;
        casenum --;
        memset(visited, false, sizeof(visited));
        memset(edgenum, 0, sizeof(edgenum));
        vector<int> graph[N];
        int u,v;
        for (int i = 0; i < citynum-1; i++) {
            cin >> u >> v;
            graph[v].push_back(u);
            graph[u].push_back(v);
        }
        if (citynum % 2 == 1) {  
            cout << "No" << endl;
            continue;
        }
        queue<int> q;
        for (int i = 1; i <= citynum; i++) {   // 将只有一条边的点push进队列
            if (graph[i].size() == 1) {
                q.push(i);
            }
        }
        bool result = true;
        int t1,t2,t3;
        while (!q.empty()) {               // 队列不为空都继续进行操作
            t1 = q.front();                // 获取队列首部的数
            q.pop();
            if (visited[t1] == true) {     // 当这个点已经与之前的点配对了，直接跳过
                continue;
            }
            else {
                visited[t1] = true;
                t2 = graph[t1][0];
                if (visited[t2] == true) { // 当这个点的配对点已经配对过了，说明发生了冲突，表示无解
                    result = false; break; 
                }
                visited[t2] = true;
                for (int j = 0; j < graph[t2].size() && visited[graph[t2][j]] == false; j++) {
                    t3 = graph[t2][j];
                    if (t3 == t1) continue;
                    graph[t3].erase(find(graph[t3].begin(), graph[t3].end(), t2));   // 对删除有配对点t2的边
                    if (graph[t3].size() == 1) {    // 若某个点的边只剩一条，则将其推入队列中
                        q.push(t3);
                    }
                    else if(graph[t3].empty()){
                        result = false;
                        break;
                    }
                }
            }
        }
        if (result == true) cout << "Yes" << endl;
        else cout << "No" << endl;
        
    }
    return 0;
}