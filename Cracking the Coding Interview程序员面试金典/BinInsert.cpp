
//题目描述
//
//有两个32位整数n和m，请编写算法将m的二进制数位插入到n的二进制的第j到第i位, 其中二进制的位数从低位数到高位且以0开始。
//给定两个数int n和int m，同时给定int j和int i，意义如题所述，请返回操作后的数，保证n的第j到第i位均为零，且m的二进制位数小于等于i - j + 1。
//测试样例：
//1024，19，2，6
//返回：1100

class BinInsert {
public:
	int binInsert(int n, int m, int j, int i) {
		// write code here
		////保证n的j到i位均为0，且m的二进制位数小于等于i-j+1
		//return n | (m << j);

		////取m的每一位，和n的对应位相与
		//int k = 0;
		//while (m!=0)
		//{
		//	int bit = m & 1;
		//	if (bit)
		//	{
		//		n |= 1 << (k + j);//为1，这一位也要为1，所以或
		//	}
		//	else
		//	{
		//		n &= ~(1 << (k + j));
		//	}
		//	k++;
		//	m >>= 1;
		//}

		//清零的方式  //定义掩码
		int mask = ~(((1 << (i - j + 1)) - 1) << j);  //111->111000->000111;对后面的没有影响
		n &= mask;  //i～j位置为0
		n |= (m << j);

		return n;
	}
};


#include <iostream>
using namespace std;

int main()
{
	int i = 5, j = 2;
    int	n = 234;
	int m = 9;
	//清零的方式
	int mask = ~(((1 << (i - j + 1)) - 1) << j);  //
	n &= mask;  //i～j位置为0
	n |= (m << j);
	cout << mask;
	return	0;
}