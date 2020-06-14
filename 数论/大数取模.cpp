// 大数取模

int mod(string big, int basic)
{
    int div = 0;
    for (int i = 0; i < big.length(); ++i) {
        div = div * 10 + big[i] - '0';
        div %= basic;
    }
    return div;
}

// 大数乘法取模
 
long long mulAndMod(long long x, long long y, long long mod) { 
    long long ret = 0;
    while(y) {
        if(y & 1) ret = (ret + x) % mod;
        x = x * 2 % mod;
        y >>= 1;
    }
    return ret;
}
