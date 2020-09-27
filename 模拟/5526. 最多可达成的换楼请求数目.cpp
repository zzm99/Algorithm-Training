class Solution {
public:
    int maximumRequests(int n, vector<vector<int>>& requests) {
        int size=requests.size();
        int res=0;
        for(int i=0;i<(1<<size);i++){//枚举所有的状态
            res=max(res,fun(requests,n,i));
        }
        return res;
    }
    int fun(vector<vector<int>>& req,int n,int state){
        vector<int> w_in(n,0),w_out(n,0);//如果对于每一栋楼，想进来和想出去的人数是一样的，那么这个状态就是合法的
        int index=0;//标记到哪一个请求了
        int ret=0;
        while(state){
            if(state&1){
                w_out[req[index][0]]++;
                w_in[req[index][1]]++;
                ret++;
            }
            index++;
            state>>=1;
        }
        for(int i=0;i<n;i++){
            if(w_in[i]!=w_out[i]){
                return -1;
            }
        }
        return ret;
    }
};