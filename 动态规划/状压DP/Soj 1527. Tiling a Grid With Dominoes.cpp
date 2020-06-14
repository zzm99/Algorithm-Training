#include<iostream>
#include<string.h>
using namespace std;
int f[1005][5];

int Domi(int n) {
	f[0][0] = 1;
	for (int i = 1; i <= n; ++i) {
		f[i][0] = f[i - 1][0] + f[i - 1][1] + f[i - 1][2] + f[i - 1][3];
		if (i > 1) f[i][0] += f[i - 2][0];
		f[i][1] = f[i - 1][0] + f[i - 1][2];
		f[i][2] = f[i - 1][0] + f[i - 1][1];
		f[i][3] = f[i - 1][0] + f[i - 1][4];
		f[i][4] = f[i - 1][3];
	}
	return f[n][0];
}

int main() {
	int n;
	cin >> n;
	int counter = 1;
    Domi(1005);
	for (int i = 0; i < n; ++i) {
		int num;
		cin >> num;
		cout << counter << " " << f[num][0] << endl;
		counter++;
	}
	return 0;
}
