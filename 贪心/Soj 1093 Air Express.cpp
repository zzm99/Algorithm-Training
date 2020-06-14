#include<iostream>
#include<cstdio>
using namespace std;
 
int main() {
    int t = 1;
    int w1, w2, w3;
    int r1, r2, r3, r4;
    while (cin >> w1) {
        cin >> r1 >> w2 >> r2 >> w3 >> r3 >> r4;
        printf("Set number %d:\n", t++);
        int n;
        while(cin >> n && n) {
            int price, add = 0;
            int minprice;
            if (n <= w1) {
                minprice = n * r1;
                price = (w1 + 1) * r2;
                if (price < minprice) {
                    minprice = price;
                    add = w1 + 1 - n;
                }
            }
            else if (n <= w2) {
                minprice = n * r2;
                price = (w2 + 1) * r3;
                if (price < minprice) {
                    minprice = price;
                    add = w2 + 1 - n;
                }
            }
            else if (n <= w3) {
                minprice = n * r3;
                price = (w3 + 1) * r4;
                if (price < minprice) {
                    minprice = price;
                    add = w3 + 1 - n;
                }
            }
            else {
                minprice = n * r4;
                add = 0;
            }
            printf("Weight (%d) has best price $%d (add %d pounds)\n", n, minprice, add);
        }
        printf("\n");
    }
}