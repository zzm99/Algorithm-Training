class Solution {
public:
    int getRoot(vector<int>& par,int x){
        int root = x;
        while(par[root]!=root){
            root = par[root];
        }
        while(par[x]!=root){
            int tmp = par[x];
            par[x] = root;
            x = tmp;
        }
        return root;
    }
    bool merge(vector<int>& par,int x,int y){
        int _x = getRoot(par,x);
        int _y = getRoot(par,y);
        if(_x!=_y){
            par[_x]=_y;
            return true;
        }
        return false;
    }
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        vector<int>par1 = vector<int>(n+1,0);
        vector<int>par2;
        int ans = 0;
        int cnt1 = n,cnt2;
        for(int i =1;i<=n;i++){
            par1[i] = i;
        }
        //先添加第三种类型的边
        for(int i = 0;i<edges.size();i++){
            if(edges[i][0]==3){
                if(!merge(par1,edges[i][1],edges[i][2]))
                    ans++;
                else
                    cnt1--;
            }
        }
        par2 = par1;
        cnt2 = cnt1;
        //再添加其余两种类型的边
        for(int i = 0;i<edges.size();i++){
            if(edges[i][0]==1){
                if(!merge(par1,edges[i][1],edges[i][2]))
                    ans++;
                else
                    cnt1--;
            }else if(edges[i][0]==2){
                if(!merge(par2,edges[i][1],edges[i][2]))
                    ans++;
                else
                    cnt2--;
            }
        }
        if(cnt1!=1||cnt2!=1)
            return -1;
        return ans;
    }
};
