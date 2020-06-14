#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    int r0=20, r1=20, r2=20, r3=25, r4=25, r5=30, r6=30;
    while(true) {
        int w0, w1, w2, w3, w4, w5, w6;
        cin >> w0 >> w1 >> w2 >> w3 >> w4 >> w5 >> w6;
        if(w0==0 && w1==0 && w2==0 && w3==0 && w4==0 && w5==0 && w6==0) break;
        int res = 0;
        if(w0 > 0) {
            res += w0/r0;
            if(w0 % r0 != 0) {
                int t = r0 - w0 % r0;
                if(t < w1) w1 -= t;
                else w1 = 0;
                res++;
            }
        }
        if(w1 > 0) {
            res += w1/r1;
            if(w1 % r1 != 0) {
                int t = r1 - w1 % r1;
                if(t < w2) w2 -= t;
                else w2 = 0;
                res++;
            }
        }
        if(w2 > 0) {
            res += w2/r2;
            if(w2 % r2 != 0) {
                int t = r2 - w2 % r2;
                if(t < w3) w3 -= t;
                else w3 = 0;
                res++;
            }
        }
        if(w3 > 0) {
            res += w3/r3;
            if(w3 % r3 != 0) {
                int t = r3 - w3 % r3;
                if(t < w4) w4 -= t;
                else w4 = 0;
                res++;
            }
        }
        if(w4 > 0) {
            res += w4/r4;
            if(w4 % r4 != 0) {
                int t = r4 - w4 % r4;
                if(t < w5) w5 -= t;
                else w5 = 0;
                res++;
            }
        }
        if(w5 > 0) {
            res += w5/r5;
            if(w5 % r5 != 0) {
                int t = r5 - w5 % r5;
                if(t < w6) w6 -= t;
                else w6 = 0;
                res++;
            }
        }
        if(w6 > 0) {
            res += w6/r6;
            if(w6 % r6 != 0) {
                res++;
            }
        }
        cout << res << endl;
    }
    return 0;
}