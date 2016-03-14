//题目描述
//
//输入一个int型整数，按照从右向左的阅读顺序，返回一个不含重复数字的新的整数。
//
//输入描述 :
//输入一个int型整数
//
//
//输出描述 :
//按照从右向左的阅读顺序，返回一个不含重复数字的新的整数


#include<iostream>
using namespace std;
int main()
{
	int input,output=0;
	while (scanf("%d",&input)!=EOF)
	{
		int num = input,bit;
		bool num_flag[10] = {false};
		while (num)
		{
			bit = num % 10;
			if (!num_flag[bit])  //关键的方法：去重
			{
				num_flag[bit] = true;
				cout << bit;
			}	
			//output = bit + 10 * output; 不用整个输出，一位位输出
			num = num / 10;
		}
		cout << endl;
		//printf("%d\n", output);
	}
	return 0;
}
