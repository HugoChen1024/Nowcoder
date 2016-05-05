
/*****************************************************
* \file SetOfStacks.cpp
* \date 2016/05/05 17:49

* \问题描述：
请实现一种数据结构SetOfStacks，由多个栈组成，其中每个栈的大小为size，当前一个栈填满时，新建一个栈。
该数据结构应支持与普通栈相同的push和pop操作。
给定一个操作序列int[][2] ope(C++为vector<vector<int>>)，每个操作的第一个数代表操作类型，
若为1，则为push操作，后一个数为应push的数字；若为2，则为pop操作，后一个数无意义。
请返回一个int[][](C++为vector<vector<int>>)，为完成所有操作后的SetOfStacks，顺序应为从下到上，默认初始的SetOfStacks为空。保证数据合法。

* \问题分析：
这道题目基本没什么技巧，就是堆栈入栈的过程，相当于用多个数组来实现一个堆栈，如果一个数组满了，
则使用另一数组，如果当且数组空了，则把该数组删除，从它前一个数组中操作，实现的时候注意数组交换数组时应该如何判断。

*****************************************************/

#include <iostream>
using namespace std;
#include <vector>
class SetOfStacks {
public:
	vector<vector<int> > setOfStacks(vector<vector<int> > ope, int size) {
		// write code here
		if (ope.size()==0)
		{
			return ope;
		}
		vector<vector<int>> vec_result;
		vector<int> vec;
		int top = 0;
		for (int i = 0; i < ope.size();i++)
		{
			if (ope[i][0]==1)   //按顺序执行，则不需要if--else
			{
				vec.push_back(ope[i][1]);
				if (++top==size)  //栈满，则新建一个栈
				{
					vec_result.push_back(vec);
					vec.clear();
					top = 0;
				}
			}
			else
			{
				if (top==0)  //栈为空，则从上一个栈出
				{
					vec = vec_result.back();
					vec_result.pop_back();
					top = size;
				}
				vec.pop_back();
				top--;
			}
		}

		//vector<vector<int> > st;
		//vector<int> temp;
		//for (int i = 0; i < ope.size(); i++){
		//	if (ope[i][0] == 1){//入栈
		//		if (temp.size() == size){//栈满，则新建一个栈，再入栈
		//			st.push_back(temp);
		//			temp.clear();
		//			temp.push_back(ope[i][1]);
		//		}
		//		else
		//			temp.push_back(ope[i][1]);
		//	}
		//	if (ope[i][0] == 2){//出栈
		//		if (temp.size() != 0)//当前栈不为空，直接出栈
		//			temp.pop_back();
		//		else if (st.size() != 0){//当前栈为空，则从上一个栈出
		//			temp = st[st.size() - 1];
		//			temp.pop_back();
		//			st.pop_back();
		//		}
		//	}
		//}

		if (!vec.empty())   //对于没有满size但又有元素的vec,最后压入返回结果
		{
			vec_result.push_back(vec);
		}
		return vec_result;
	}
};