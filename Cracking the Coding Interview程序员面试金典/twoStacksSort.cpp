/*****************************************************
* \file twoStacksSort.cpp
* \date 2016/05/07 23:58

* \问题描述：
请编写一个程序，按升序对栈进行排序（即最大元素位于栈顶），要求最多只能使用一个额外的栈存放临时数据，但不得将元素复制到别的数据结构中。
给定一个int[] numbers(C++中为vector&ltint>)，其中第一个元素为栈顶，请返回排序后的栈。请注意这是一个栈，意味着排序过程中你只能访问到第一个元素。
测试样例：
[1,2,3,4,5]
返回：[5,4,3,2,1]

* \问题分析：



*****************************************************/


#include<iostream>
using namespace std;
#include<vector>

class TwoStacks {
public:
	vector<int> twoStacksSort(vector<int> numbers) {
		// write code here
		vector<int> ans;
		if (numbers.size()==0)
		{
			return ans;
		}
		while (numbers.size()!=0)
		{
			int temp = numbers.back();
			numbers.pop_back();
			while (ans.size()!=0&&temp<ans.back())     //num 4 3 5 1 2 (后面为back)
			{
				numbers.push_back(ans.back());
				ans.pop_back();
			}
			ans.push_back(temp);
		}
		while (ans.size()!=0)   
		{
			numbers.push_back(ans.back());  //此时num为空
			ans.pop_back();
		}
		return numbers;
	}
};