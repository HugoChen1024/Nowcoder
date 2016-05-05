//#include<iostream>
//using namespace std;
//
//class Base {
//public:
//	Base(int j) : i(j)  {}
//	virtual~Base() {}
//	void func1() {
//		i *= 10;
//		func2();
//	}
//	int getValue() {
//		return  i;
//	}
//protected:
//	virtual void func2() {
//		i++;
//	}
//protected:
//	int i;
//};
//
//class Child : public Base {
//public:
//	Child(int j) : Base(j) {}
//	void func1() {
//		i *= 100;
//		func2();
//	}
//protected:
//	void func2() {
//		i += 2;
//	}
//};
//int main() {
//	Base * pb = new Child(1);
//	pb->func1();
//	cout << pb->getValue() << endl;  ///12
//	delete pb;
//}

/*****************************************************
* \file Palindrome listNode.cpp
* \date 2016/05/05 17:16

题目描述

请编写一个函数，检查链表是否为回文。
给定一个链表ListNode* pHead，请返回一个bool，代表链表是否为回文。
测试样例：
{1,2,3,2,1}
返回：true
{1,2,3,2,3}

返回：false

*****************************************************/

struct ListNode
{
	int val;
	struct ListNode *next;
	ListNode(int x) :val(x), next(nullptr){}
};


#include <iostream>
#include <stack>
using namespace std;

class Palindrome {
public:
	bool isPalindrome(ListNode* pHead) {
		// write code here
		ListNode *pNode = pHead;
		stack<int> s;
		while (pNode)
		{
			s.push(pNode->val);
			pNode = pNode->next;
		}
		pNode = pHead;
		while (pNode)
		{
			if (pNode->val==s.top())
			{
				pNode=pNode->next;
				s.pop();
			}
			else
			{
				return false;
			}
		}
		return true;
	}
};