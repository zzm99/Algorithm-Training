public int numberOfWays(int num_people) {
        int mod = (int) 1e9 + 7;
        int len = num_people / 2;
        long[] results = new long[len + 1];
        results[0] = 1;
        results[1] = 1;
        long result;
        for (int i = 2; i <= len; i++) {
            result = 0;
            for (int j = 1; j <= i; j++) {
                result += (results[j - 1] * results[i - j]) % mod;
                result %= mod;
            }
            results[i] = result;
        }
        return (int) results[len];
    }