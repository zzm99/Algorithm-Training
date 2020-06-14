#include <iostream>
#include <math.h>
using namespace std;
 
int prime[10000];			//  存储素数的数组
int ProdecePrime(void)		//  用于产生素数的函数，返回值是数组的长度
{
	int count = 0, i, j, tem;
	prime[count++] = 2;
	prime[count++] = 3;
	//  找出所有小于10000的素数存于prime数组中
	for (i = 5; i < 10000; i++)
	{
		tem = (int)sqrt(i);
		for (j = 2; j <= tem; j++)
			if (i % j == 0)
				break;
		if (j == tem + 1)
			prime[count++] = i;
	}
	return count;
}
 
int main()
{
	int n, count, sum, ans;
	count = ProdecePrime();		//  产生素数并获取数组长度
	while (1)
	{
		cin >> n;
		if (n == 0)
			break;
		ans = 0;
		for (int i = 0; i < count; i++)
		{
			sum = 0;		//  sum 用于表示连续几个素数的和
			for (int j = i; j < count; j++)
			{
				if (prime[j] > n || sum > n)
					break;
				sum += prime[j];
				if (sum == n)
				{
					ans++;
					break;
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}