#include <cstdio>
 
using namespace std;
 
int main()
{
    for(int i = 2992; i <= 9999; i++)
    {
        int temp = i, sum = 0, sum_16 = 0, sum_12 = 0;
        while(temp > 0)
        {
            sum += temp % 10;
            temp /= 10;
        }
        temp = i;
        while(temp > 0)
        {
            sum_16 += temp % 16;
            temp /= 16;
        }
        temp = i;
        while(temp > 0)
        {
            sum_12 += temp % 12;
            temp /= 12;
        }
        if(sum == sum_12 && sum == sum_16) printf("%d\n", i);
    }
    return 0;
}