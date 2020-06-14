#include <cstdio>
#include <cmath>

int benchmark(int y) {
    int e = (y - 1960) / 10 + 2;
    int left = 1 << e;
    int k = 0;
    double res = 0;
    while (left > res) {
        res += log(++k) / log(2);
    }
    return --k;
}

int main() {
    int y;
    while (scanf("%d", &y), y) {
        int k = benchmark(y);
        printf("%d\n", k);
    }
    return 0;
}