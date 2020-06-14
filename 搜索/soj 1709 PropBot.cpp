#include<bits/stdc++.h>
using namespace std;

int TIME;
double X, Y;
double MIN;
double MIN_X, MIN_Y;
double SQRT = sqrt(0.5);
double DIR[8][2] = {{1,0}, {SQRT, -1*SQRT}, {0, -1}, {-1*SQRT, -1*SQRT}, 
                    {-1, 0}, {-1*SQRT, SQRT}, {0, 1}, {SQRT, SQRT}};

struct Node{
    double x, y;
    int dir;
    int time;
}; 

double dist(Node n){
    return ((n.x - X)*(n.x - X) + (n.y - Y)*(n.y - Y));
}

void BFS(){
    Node n;
    n.x = n.y = 0;
    n.time = 0;
    n.dir = 0;
    queue<Node> q;
    if(n.time <= TIME){
        if(dist(n) < MIN){
            MIN = dist(n);
            MIN_X = n.x;
            MIN_Y = n.y;
        }
        q.push(n);
    } 
    
    while(!q.empty()){
        Node front = q.front();
        q.pop();
        double d = dist(front);
        Node t1 = front;
        t1.x += 10*DIR[t1.dir][0];
        t1.y += 10*DIR[t1.dir][1];
        t1.time++;
        if(t1.time <= TIME){
            if(dist(t1) < MIN){
                MIN = dist(t1);
                MIN_X = t1.x;
                MIN_Y = t1.y;
            }
            q.push(t1);
        }
        Node t2 = front;
        t2.dir = (++t2.dir) ;
        t2.time++;
        if(t2.time <= TIME && t2.dir < 8){
            q.push(t2);
        }
    }
}
int main(){
    int t;
    cin >> t;
    while(t--){
        cin >> TIME >> X >> Y;
        MIN = 10000000;
        BFS();
        printf("%.6f\n", sqrt(MIN));
    }
}