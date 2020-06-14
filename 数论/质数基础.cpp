// 判断一个数是否为质数
bool is_prime(int n) {
	for(int i=2; i*i<=n; i++) {
		if(n % i == 0) {
			return false;
		}
	}
	return true;
}

// 求出一个范围内的所有质数
const int maxn = 100;
bool composite[maxn];
void gen_prime() {
	for(int i=2; i<maxn; i++) {
		if(composite[i]) continue;
		for(int j=i*i; j<maxn; j+=i)
			composite[j] = true;
	}
}

// 求出一个范围内的所有质数O(n)
void linear_gen_prime() {
	int tot = 0;
	for(int i=2; i<maxn; i++) {
		if(!composite[i]) prime[tot++] = i;
		for(int j=0; j<tot; j++) {
			if(prime[j] * i >= maxn) break;
			composite[prime[j] * i] true;
			if(i % prime[j] == 0) break;
		}
	}
}

// 对一个数做质因子分解
vector<long long> factor(long long n) {
	vector<long long> ret;
	for(long long i = 2; i*i <= n; i++) {
		while(n % i == 0) {
			ret.push_back(i);
			n /= i;
		}
	}
	if(n > 1) ret.push_back(n);
	return ret;
}