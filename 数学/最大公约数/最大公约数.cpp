int gcd(int a, int b) {
	if(b == 0) return a;
	return gcd(b, a % b);
} // gcd(a, b) * lcm(a, b) = a * b

int Exgcd(int a, int b, int &x, int &y) {
	if(!b) {
		x = 1;
		y = 0;
		return a;
	}
	int d = Exgcd(b, a % b, x, y);
	int t = x;
	x = y;
	y = t - (a / b) * y;
	return d;
}