#include <iostream>
class Node {
public:
    Node* l;
    Node* r;
    int s;
    int e;
    int m;
    int val;
    bool tag;   ///是否为叶子节点，true为叶子节点
    Node(int s, int e) : l(nullptr), r(nullptr), s(s), e(e), m((s+e)/2), val(0), tag(true) {}
    Node* Left() {
        if (s == e) return nullptr;
        l = l ? l : new Node(s, m);
        return l;
    }
    Node* Right() {
        if (s == e) return nullptr;
        r = r ? r : new Node(m+1, e);
        return r;
    }
    void add(int index) {
        val++;
        if(s==e){
            return;
        }
        if(index<=m){
            Left()->add(index);
        }else{
            Right()->add(index);
        }
    }
    int query(int start, int end) {
        if (s == start && e == end) return val;
      
        if (end <= m) return Left()->query(start, end);
        if (start >= m+1) return Right()->query(start, end);
        return (Left()->query(start, m)+Right()->query(m+1, end));
    }
};



class Solution {
public:
    string minInteger(string num, int k) {
        int N=num.size();
        vector<queue<int>> vNumIndex(10);  //10个数字的位置

        Node node(0,N);
        
        for(int i=0;i<N;i++){
            int j=num[i]-'0';
            vNumIndex[j].push(i);
        }
        int index=0;
        string ans;

        while(index<N){

            for(int i=0;i<10;i++){
                if(vNumIndex[i].empty()){
                    continue;
                }
                int m=vNumIndex[i].front();
           
                int t=node.query(m+1,N)+m;
                int x=t-index;
                //cout<<ans<<" "<<index<<" "<<i<<" "<<x<<endl;
                if(x>k){
                    continue;  //不够交换
                }
                k-=x;
                ans.push_back(i+'0');
                vNumIndex[i].pop();
                if(x>0){
                    node.add(m);                 
                }

                index++;
                break;
            }
            
        }
              
        return ans;
    }
};
