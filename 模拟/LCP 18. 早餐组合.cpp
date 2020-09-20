class Solution {
public:
    int breakfastNumber(vector<int>& staple, vector<int>& drinks, int x) {
        const int mod = 1e9 + 7;
        int ans = 0;
        sort(staple.begin(), staple.end());
        sort(drinks.begin(), drinks.end());
        int j = drinks.size() - 1;
        for (int i = 0; i < staple.size(); i++) {
            while (j >= 0 && staple[i] + drinks[j] > x) j--;
            if (j == -1) break;
            ans += j + 1;
            ans %= mod;
        }
        return ans;
    }
};
