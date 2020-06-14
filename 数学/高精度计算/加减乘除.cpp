void add(int a[], int b[], int c[]) {
	clear(c);
	for(int i=0; i<LEN-1; i++) {
		c[i] += a[i] + b[i];
		if(c[i] >= 10) {
			c[i+1] += 1;
			c[i] -= 10;
		}
	}
}

void sub(int a[], int b[], int c[]) {
	clear(c);
	for(int i=0; i<LEN-1; i++) {
		c[i] += a[i]-b[i];
		if(c[i] < 0) {
			c[i+1] -= 1;
			c[i] += 10;
		}
	}
}

void mul_short(int a[], int b, int c[]) {
	clear(c);
	for(int i=0; i<LEN-1; i++) {
		c[i] += a[i] * b;
		if(c[i] >= 10) {
			c[i+1] += c[i]/10;
			c[i] %= 10;
		}
	}
}

void mul(int a[], int b[], int c[]) {
	clear(c);
	for(int i=0; i<LEN-1; i++) {
		// 这里直接计算结果中的从低到高第 i 位，且一并处理了进位
    	// 第 i 次循环为 c[i] 加上了所有满足 p + q = i 的 a[p] 与 b[q] 的乘积之和
		for(int j=0; j<=i; j++) c[i] += a[j] * b[i-j];
		if(c[i] >= 10) {
			c[i+1] += c[i] / 10;
			c[i] %= 10;
		}
	}
}

/* 除法 */
inline bool greater_eq(int a[], int b[], int last_dg, int len) {
	if(a[last_dg+len] != 0) return true;
	for(int i=len-1; i>=0; i--) {
		if(a[last_dg+i] > b[i]) return true;
		if(a[last_dg+i] < b[i]) return false;
	}
	return true;
}

void div(int a[], int b[], int c[], int d[]) {
	clear(c);
	clear(d);
	int la, lb;
	for(la = LEN-1; la > 0; la--) if(a[la-1] != 0) break;
	for(lb = LEN-1; lb > 0; lb--) if(b[lb-1] != 0) break;
	if(lb == 0) {
		puts("> <");
		return;
	}
	for(int i=0; i<la; i++) d[i] = a[i];
	for(int i=la-lb; i>=0; i--) {
		while(greater_eq(d, b, i, lb)) {
			for(int j=0; j<lb; j++) {
				d[i+j] -= b[j];
				if(d[i+j] < 0) {
					d[i+j+1] -= 1;
					d[i+j] += 10;
				}
			}
			c[i] += 1;
		}
	}
}
