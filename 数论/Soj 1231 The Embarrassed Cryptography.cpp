#include <iostream>
#include <math.h>
#include <string>
using namespace std;
 
int prime[100000];			//  存储素数的数组
int ProdecePrime(void)		//  用于产生素数的函数，返回值是数组的长度
{
	int count = 0, i, j, tem;
	prime[count++] = 2;
	prime[count++] = 3;
	//  找出所有小于1000000的素数存于prime数组中
	for (i = 5; i < 1000000; i++)
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
	int L, count,length, mod;
	string s;
	bool flag;
	count = ProdecePrime();		//  产生素数并获取数组长度
	while (1)
	{
		cin >> s >> L;
		if (s == "0" && L == 0)
			break;
		length = s.size();
		flag = true;			//  用于标记是否应该输出GOOD，值为true时输出
		for (int i = 0; i < count; i++)
		{
			if (prime[i] >= L)
				break;
			mod = 0;
			for (int j = 0; j < length; j++)	//  大数求模
				mod = (mod * 10 + (s[j] - '0')) % prime[i];
			if (mod == 0 && prime[i] < L)
			{
				cout << "BAD " << prime[i] << endl;
				flag = false;		//  改变标记，避免重复输出
				break;
			}
		}
		if (flag)
			cout << "GOOD" << endl;
	}
	return 0;
}