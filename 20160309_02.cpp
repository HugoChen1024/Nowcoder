//题目描述
//
//明明想在学校中请一些同学一起做一项问卷调查，为了实验的客观性，他先用计算机生成了N个1到1000之间的随机整数（N≤100），
//对于其中重复的数字，只保留一个，把其余相同的数去掉，不同的数对应着不同的学生的学号。然后再把这些数从小到大排序，
//按照排好的顺序去找同学做调查。请你协助明明完成“去重”与“排序”的工作。
//
//Input Param
//n               输入随机数的个数
//inputArray      n个随机整数组成的数组
//
//Return Value
//OutputArray    输出处理后的随机整数
//
//注：测试用例保证输入参数的正确性，答题者无需验证。
//
//输入描述 :
//输入多行，先输入随机整数的个数，在输入相应个数的整数
//
//输出描述 :
//返回多行，处理后的结果
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	int n,temp;
	//cin >> n;
	while (cin>>n)  //这样为什么288个数就没有错误了
	{
		////可以先存数据的时候，把重复数据去掉，在排序，也可以先排序在去重
		vector<int> vec;
		for (size_t i = 0; i < n; i++)
		{
			cin >> temp;
			vec.push_back(temp);
			//vec[i]=temp;
		}
		sort(vec.begin(), vec.end()); 
		if (n == 1)
		{
			cout << vec[0] << endl;
		}
		else
		{
			cout << vec[0] << endl;
			for (size_t i = 1; i < vec.size(); i++)
			{
				if (vec[i] != vec[i - 1])
				{
					cout << vec[i] << endl;
				}
			}
			/*vector<int>::iterator it;
			for (it = vec.begin(); it != vec.end(); it++)
			{
				cout << *it << endl;
			}*/
		}
	}
	return 0;
}


