#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int number, numT;
    while (cin >> number && number != 0) {
        numT = number;
        int k = 0;
        int result = 0;
        while (number) {
            int t = number % 10;
            t = t >= 5 ? t - 1 : t;
            result += t * pow(9, k++);
            number /= 10;
        }
        cout << numT << ": " << result << endl;
    }
    return 0;
}