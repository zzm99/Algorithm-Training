unordered_map<int, int> H;

int solve(int n)
{
    if (H.count(n)) return H[n];
    int &res = H[n];
    if (n == 0) return res = 0;
    if (n == 1) return res = 1;
    int tmp1 = n-n/2*2 + 1 + solve(n/2);
    int tmp2 = n-n/3*3 + 1 + solve(n/3);
    return res = min(tmp1, tmp2);
}

class Solution {
public:
    int minDays(int n) {
        return solve(n);
    }
};