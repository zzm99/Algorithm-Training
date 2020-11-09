// == key
while(l <= r) {
	int m = (l + r) >> 1;
	if(x[m] == key) 
		return m;
	else if(key > x[m]) 
		l = m+1;
	else 
		r = m-1;
}

// >= key中的最小
while(l <= r) {
	int m = (l + r) >> 1;
	if(x[m] >= key) {
		ret = m;
		r = m-1;
	} else {
		l = m+1;
	}
}

// <= key中的最大
while(l <= r) {
    int m = (l + r) >> 1;
    if(x[m] <= key) {
    	ret = m;
    	l = m+1;
    } else {
    	r = m-1;
    }
}