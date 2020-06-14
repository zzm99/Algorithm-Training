#include<bits/stdc++.h>
using namespace std;

struct Node{
    int M, V;
    friend bool operator < (const Node n1, const Node n2){
        return n1.V < n2.V;
    }
};

bool cmp(Node n1, Node n2){
    return n1.M < n2.M;
}

int main(){
    int N, K;
    while(cin >> N >> K){
        Node arr[N];
        for(int i = 0; i < N; i++)cin >> arr[i].M >> arr[i].V;
        sort(arr, arr+N, cmp);
        long long pkg[K];
        for(int i = 0; i < K; i++) cin >> pkg[i];
        sort(pkg, pkg+K);
        
        priority_queue<Node> pq;
        long long ans = 0;
        int index = 0;
        for(int i = 0; i < K; i++){
            while(index < N && arr[index].M <= pkg[i]){
                pq.push(arr[index]);
                index++;
            }
            if(!pq.empty()){
                Node n = pq.top();
                pq.pop();
                ans += n.V;    
            }
        }
        cout << ans << endl;
    }
}