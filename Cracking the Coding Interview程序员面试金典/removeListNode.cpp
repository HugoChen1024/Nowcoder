/*****************************************************
* \file removeListNode.cpp
* \date 2016/04/23 10:48

* \问题描述：
实现一个算法，删除单向链表中间的某个结点，假定你只能访问该结点。
给定带删除的节点，请执行删除操作，若该节点为尾节点，返回false，否则返回true

* \问题分析：



*****************************************************/

struct ListNode
{
	int val;
	struct ListNode* next;
	ListNode(int x) :val(x), next(nullptr){}
};

class Remove {
public:
	bool removeNode(ListNode* pNode) {   //pNode为删除节点
		// write code here
		if (pNode==nullptr||pNode->next==nullptr)
		{
			return false;
		}
		ListNode* node = pNode->next;//node删除节点
		pNode->next = node->next;
		return true;
	}
};

/*****************************************************
* \file removeListNode.cpp
* \date 2016/04/23 11:01

* \问题描述：
编写代码，以给定值x为基准将链表分割成两部分，所有小于x的结点排在大于或等于x的结点之前
给定一个链表的头指针 ListNode* pHead，请返回重新排列后的链表的头指针。注意：分割以后保持原来的数据顺序不变。

* \问题分析：
要是链表换作数组要特别小心，因为搬迁数组要涉及到移动元素的开销，而移动链表的元素则容易很多，我们不需要移动和交换链表中的元素，
只是改变一下每个节点的next指针就可以，我们可以创建两个链表，一个链表是存放小于x的元素，另一个链表存放大于等于x的元素，
然后遍历一遍原有链表，将小于x元素的节点加到第一个链表上，将大于等于x元素的节点加到第二个链表上。便可实现分割。
《程序员面试金典》题目详解：http://blog.csdn.net/zdplife/article/category/5799903

或者：
时间O(n)， 空间O(1)的做法。
大致思路是从头到尾遍历一遍，若val大于x，则将该结点转移到List的尾部。
思路很简单，需要注意是如何在转移结点时找到它的父结点，防止List断掉。

*****************************************************/
class Partition {
public:
	ListNode* partition(ListNode* pHead, int x) {
		// write code here
		ListNode *pSamllFirst = new ListNode(0);
		ListNode *pBigFirst = new ListNode(0);
		ListNode *pSamll = pSamllFirst, *pBig = pBigFirst;

		if (pHead==nullptr)
		{
			return pHead;
		}
		while (pHead)
		{
			if (pHead->val<x)
			{
				pSamll->next = pHead;
				pSamll = pSamll->next;
			}
			else
			{
				pBig->next = pHead;
				pBig = pBig->next;
			}
			pHead = pHead->next;
		}
		pBig->next = nullptr;
		pSamll->next = pBigFirst->next;
		return pSamllFirst->next;
	}
};

#include <iostream>
using namespace std;
int main()
{


	return 0;
}