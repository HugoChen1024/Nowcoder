
//题目描述
//
//有一个介于0和1之间的实数，类型为double，返回它的二进制表示。如果该数字无法精确地用32位以内的二进制表示，返回“Error”。
//给定一个double num，表示0到1的实数，请返回一个string，代表该数的二进制表示或者“Error”。
//测试样例：
//0.625
//返回：0.101


//两种方法，正向和逆向

#include <iostream>
using namespace std;
#include <string>

class BinDecimal {
public:
	string printBin(double num) {
		// write code here
		double base = 0.5;
		string str = "0.";
		while (num)
		{
			if (num>=base)
			{
				num -= base;
				str += "1";
			}
			else
			{
				str += "0";
			}
			if (str.size()>=32)
			{
				str = "Error";
				break;
			}
	//		num -= base;  逻辑错误
			base=base/2;
		}
		return str;
	}
};

class BinDecimal {
public:
	string printBin(double num) {
		// write code here
		string str = "0.";
		for (int i = 0; i < 32;i++)
		{
			num *= 2;
			if (num>=1)
			{
				str += "1";
				num -= 1.0;
			}
			else
			{
				str += "0";
			}
			if (num<=0.0)
			{
				return str;
			}
		}
		if (num>0.0)
		{
			return "Error";
		}
		return str;
	}
};

int main()
{
	double val = 0.625;
	BinDecimal b;
	cout<<b.printBin(val)<<endl;
	return 0;
}