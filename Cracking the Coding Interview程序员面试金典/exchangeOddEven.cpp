//题目描述
//
//请编写程序交换一个数的二进制的奇数位和偶数位。（使用越少的指令越好）
//给定一个int x，请返回交换后的数int。
//测试样例：
//10
//返回：5

class Exchange {
public:
	int exchangeOddEven(int x) {
		// write code here
		int result = 0;
		int times = 0;
		while (x!=0)
		{
			times = times + 2;
			int a = x & 1;
			result += a * pow(times-1);
			x >>= 1;
			int b = x & 1;
			result += b*pow(times - 2);
			x >>= 1;
		}
		return result;
	}
	int pow(int x)
	{
		int a = 1;
		while (x!=0)
		{
			a*=2;
			x--;
		}
		return a;
	}

	//用0xAAAAAAAA与x相与求的奇数位上数字(偶数位上数字为0)
	//	用0x 55555555 与x相与求的偶数位上数字(奇数位上数字为0)

	//	oddVal右移一位 even左移一位  相加即可。
	int exchangeOddEven(int x) {
		// write code here
		int oddVal = (x & 0xAAAAAAAA); // bit 1 3 5 ... 31
		int evenVal = (x & 0x55555555); // bit 0 2 4 ... 30
		return (oddVal >> 1) + (evenVal << 1);
	}

	//因为int是有符号整型，所以如果x的最高位为1，那么取偶数位得到的数even的最高位也为1，如果此时右移，那么最高位补1而不是0，后面或的时候就有可能出问题，因为1 | 0等于1，改变了不该变的值。
};



#include<iostream>
using namespace std;

int main()
{
	Exchange e;
	cout << e.exchangeOddEven(10) << endl;
	return 0;
}
