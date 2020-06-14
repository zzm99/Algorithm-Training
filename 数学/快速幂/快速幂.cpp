// 快速幂 递归与非递归版
long long binpow(long long a, long long b) {
	if(b == 0) return 1;
	long long res = binpow(a, b/2);
	if(b % 2) return res * res * a;
	else return res * res;
}

long long binpow(long long a, long long b) {
	long long res = 1;
	while(b > 0) {
		if(b & 1) res = res * a;
		a = a * a;
		b >>= 1;
	}
	return res;
}

// 模意义下取幂 x^n mod m
long long binpow(long long a, long long b, long long m) {
	a %= m;
	long long res = 1;
	while(b > 0) {
		if(b & 1) res = res * a % m;
		a = a * a % m;
		b >>= 1;
	}
	return res;
}

