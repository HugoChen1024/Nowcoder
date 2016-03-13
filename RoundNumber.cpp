//题目描述
//
//写出一个程序，接受一个浮点数值，输出该数值的近似整数值。如果小数点后数值大于等于5, 向上取整；小于5，则向下取整。
//输入描述 :
//输入一个浮点数值
//
//
//输出描述 :
//输出该数值的近似整数值

#include<iostream>
using namespace std;

int main()

{
	float input;
	while (cin>>input)
	{
		//int integer = (int)input;
		int integer = static_cast<int>(input);
		if (input-integer>=0.5)
		{
			cout << integer + 1;
		}
		else
		{
			cout << integer;
		}
	}
	return 0;
}
