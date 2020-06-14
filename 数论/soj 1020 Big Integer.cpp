#include <iostream>
#include <string>
 
using namespace std;
 
int mod(string big, int basic)
{
    int div = 0;
    for (int i = 0; i < big.length(); ++i) {
        div = div * 10 + big[i] - '0';
        div %= basic;
    }
    return div;
}
 
int main()
{
    int cases;
    cin >> cases;
    int basic[100];
    while (cases--) {
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i) {
            cin >> basic[i];
        }
        string big_integer;
        cin >> big_integer;
        cout << '(';
        for (int i = 0; i < n; ++i) {
            if (i == n - 1) {
                cout << mod(big_integer, basic[i]) << ')' << endl;;
            } else {
                cout << mod(big_integer, basic[i]) << ',';
            }
        }
    }
    return 0;
}