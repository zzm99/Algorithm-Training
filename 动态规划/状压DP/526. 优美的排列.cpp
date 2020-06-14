class Solution {
public:
    int countArrangement(int N) {

        vector<int> f(1 << N, 0);
        for (int i = 0; i < N; i++)
            f[1 << i] = 1;

        for (int s = 1; s < (1 << N); s++)
            if (f[s] > 0) {
                int tot = 0;
                for (int i = 0; i < N; i++)
                    if (s & (1 << i))
                        tot++;

                for (int i = 0; i < N; i++)
                    if (!(s & (1 << i)) && ((tot + 1) % (i + 1) == 0 || (i + 1) % (tot + 1) == 0))
                        f[s | 1 << i] += f[s];
            }

        return f[(1 << N) - 1];         
    }
};
