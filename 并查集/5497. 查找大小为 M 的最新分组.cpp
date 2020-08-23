class Solution {
public:
    vector<int> fa;
    vector<int> cnt_len;
    vector<int> sum;
    
    int find(int x){
        return fa[x]==x ? x : fa[x] = find(fa[x]);
    }

    void merge(int len,int le,int ri,int idx){
        if(cnt_len[le]) fa[le] = idx;
        if(cnt_len[ri]) fa[ri] = idx;

        //更新新的长度 以及个数
        cnt_len[idx] = len;
        sum[len]++;
    }

    int findLatestStep(vector<int>& arr, int m) {
        int n = arr.size();
        fa.resize(n+10,0);
        for(int i = 0; i < n + 2; i++)
            fa[i] = i;
        cnt_len.resize(n+10,0);
        sum.resize(n+10,0);

        int ans = -1;

        for(int i = 0; i < n; i++){
            int left = find(arr[i] - 1);
            int right = find(arr[i] + 1);
            
            int len = 1 + cnt_len[left] + cnt_len[right];
            sum[cnt_len[left]]--;
            sum[cnt_len[right]]--;

            //合并
            merge(len,left,right,arr[i]);

            if(sum[m] > 0){
                ans = i+1;
            }
        }

        return ans==-1 ? -1 : ans;
    }
};