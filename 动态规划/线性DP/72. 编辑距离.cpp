class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        vector<vector<int>> cost(m+1, vector<int>(n+1));
        for(int i=0; i<=m; i++) cost[i][0] = i;
        for(int j=0; j<=n; j++) cost[0][j] = j;
        for(int i=1; i<=m; i++){
            for(int j=1; j<=n; j++){
                if(word1[i-1] == word2[j-1]){
                    cost[i][j] = cost[i-1][j-1];
                }else{
                    cost[i][j] = 1+min(cost[i-1][j-1], min(cost[i-1][j], cost[i][j-1]));
                }
            }
        }
        return cost[m][n];
    }
};