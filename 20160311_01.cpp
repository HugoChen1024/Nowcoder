//题目描述
//
//功能 : 输入一个正整数，按照从小到大的顺序输出它的所有质数的因子（如180的质数因子为2 2 3 3 5 ）
//
//	 详细描述：
//
//	 函数接口说明：
//	 public String getResult(long ulDataInput)
//	 输入参数：
//	 long ulDataInput：输入的正整数
//	 返回值：
//	 String

#include<iostream>
using namespace std;
void getResult(long input)
{
	for (long i = 2; i <= input; i++)
	{
		while (input%i==0)
		{
			cout << i << " ";
			input /= i;
		}
		//cout << endl;
	}
}
int main()
{
	long number,a;
	cin >> number;
	while (number)
	{
		getResult(number);
		cin >> number;
	}
	
	/*while (scanf("%d", &a) != EOF){    //Windows中，Ctrl-Z表示EOF。
		printf("abc");
	}*/
	return 0;
}

//#include<stdio.h>
//#include<math.h>
//
//int isprime(int n)//判断整数n是否为素数
//{
//	int i;
//	for (i = 2; i <= sqrt(n); i++)
//	{
//		if (n%i == 0)
//		{
//			return 0;
//		}
//		if (i>sqrt(n))
//		{
//			return 1;
//		}
//	}
//	return 1;
//}
//
//int main()
//{
//	int i, m;
//	scanf("%d", &m);
//
//	for (i = 2; i <= sqrt(m); i++)
//	{
//		if (m%i == 0)
//		{
//			if (isprime(i))
//			{
//				printf("%d ", i);
//				m /= i;
//				i = 1;
//			}
//
//		}
//
//	}
//	if (i>sqrt(m))
//	{
//		printf("%d ", m);
//	}
//	return 0;
//}
