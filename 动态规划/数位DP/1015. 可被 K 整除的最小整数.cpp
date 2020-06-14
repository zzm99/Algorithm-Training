class Solution {
public:
    int smallestRepunitDivByK(int K) {
        if(K % 2 == 0 || K % 5 == 0) return -1;
        int i = 1;
        for(int n=1; n%K != 0; i++) {
            n %= K;
            n = n*10 + 1;
        }
        return i;
    }
};