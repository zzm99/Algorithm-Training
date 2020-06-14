#include<bits/stdc++.h>
using namespace std;
int _move[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int visit[25][25][25][25];
int Helen_move[4];
int n,m;
char _map[100][100];
struct Node{
    int x1, y1;//Paris
    int x2, y2;//Helen
    int step;
};

Node bfs(int x1, int y1, int x2, int y2, int n, int m){
    Node front;
    front.x1 = x1;
    front.y1 = y1;
    front.x2 = x2;
    front.y2 = y2;
    front.step = 0;
    queue<Node> q;
    q.push(front);
    visit[x1][y1][x2][y2] = 1;
    while(!q.empty()){
        front = q.front(); q.pop();
        if(front.step > 255) {
            return front;//若大于255，则返回
        }
        for(int i = 0; i < 4; i++){
            int Paris_x = front.x1 + _move[i][0];//走一步
            int Paris_y = front.y1 + _move[i][1];
            if(0 <= Paris_x && Paris_x < n && 0 <= Paris_y && Paris_y < m &&
                _map[Paris_x][Paris_y] != '#' && _map[Paris_x][Paris_y] != '!'){
                int k = Helen_move[i];

                int Helen_x = front.x2 + _move[k][0];
                int Helen_y = front.y2 + _move[k][1];

                if(0 <= Helen_x && Helen_x < n && 0 <= Helen_y && Helen_y < m){
                    if(_map[Helen_x][Helen_y] == '#'){//撞墙则不走
                        Helen_x = front.x2;
                        Helen_y = front.y2;
                    }
                    else if(_map[Helen_x][Helen_y] == '!') continue;//遇到熔浆

                    if(visit[Paris_x][Paris_y][Helen_x][Helen_y] == 1) continue;
                    Node tmp = front;
                    tmp.x1 = Paris_x;
                    tmp.y1 = Paris_y;
                    tmp.x2 = Helen_x;
                    tmp.y2 = Helen_y;
                    tmp.path[tmp.step] = i;
                    tmp.step = front.step + 1;
                    q.push(tmp);
                    visit[Paris_x][Paris_y][Helen_x][Helen_y] = 1;
                    if(Paris_x == Helen_x && Paris_y == Helen_y){//直接相遇
                        return tmp;
                    }
                    if(Paris_x == front.x2 && Paris_y == front.y2 &&
                       Helen_x == front.x1 && Helen_y == front.y1){
                           return tmp;//交差相遇
                    }
                }

            }
        }
    }
    front.step = 256;
    return front;
}
int main(){
    cin >> n >> m;

    int x1, y1;
    int x2, y2;
    memset(visit, 0, sizeof(visit));
    memset(Helen_move, 0, sizeof(Helen_move));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> _map[i][j];
            if(_map[i][j] == 'P'){//Paris的位置
                x1 = i;
                y1 = j;
            }
            if(_map[i][j] == 'H'){//Helen的位置
                x2 = i;
                y2 = j;
            }
        }
    }

    for(int i = 0; i < 4; i++){
        char c;
        cin >> c;
        if(c == 'N')Helen_move[i] = 0;//Paris走时Helen的方向
        else if(c == 'S')Helen_move[i] = 1;
        else if(c == 'W')Helen_move[i] = 2;
        else if(c == 'E')Helen_move[i] = 3;
    }
     Node tmp = bfs(x1, y1, x2, y2, n, m);
    if(tmp.step > 255) cout << "Impossible" << endl;
    else{
        cout << tmp.step << endl;
    }

}
