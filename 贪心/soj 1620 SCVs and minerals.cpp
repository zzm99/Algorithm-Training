#include<iostream>
using namespace std;
int main() {
    int test;
    cin >> test;
    while (test--) {
        int N, M, C, P, S;
        cin >> N >> M >> C >> P >> S;
        while (S) {
            if (S * C > P) {
                N = N + M / P;
                M = M % P;
            }
            M += N * C;
            S--;
        }
        cout << M << endl;
    }
}      