//对于一个链表，请设计一个时间复杂度为O(n), 额外空间复杂度为O(1)的算法，判断其是否为回文结构。
//给定一个链表的头指针A，请返回一个bool值，代表其是否为回文结构。保证链表长度小于等于900。
//测试样例：
//1->2->2->1
//返回：true

#include <stdio.h>
#include <iostream>
using namespace  std;

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}
};


//思路1：空间O(n) 整个链表遍历两边， 开一个栈，第一遍遍历把链表中每个元素push进栈中，这样堆中的元素的pop顺序就是链表的倒序输出；第二遍就开始pop栈中数据，每pop一个数据，就把这个数据跟链表中进行对比，如果相同继续往下走，如果不同返回false。
//
//思路2：空间O(1)，使用快慢指针法，第一步设置一个块指针和一个慢指针，快指针一次走两步，慢指针一次走一步（慢），当快指针下一步为null的时候说明慢指针已经走了一半，这就可以找到中间节点。第二步反转中间链表后面的指针，第三部从头尾向中间扫描，对比每个元素是否相等，如果都相等，则是回文数，否则不是回文数。（下面网友易水给出了代码实现，这里不再叙述）

class PalindromeList {
public:
	bool chkPalindrome(ListNode* A) {
		// write code here
		ListNode* pHead = nullptr;
	    ListNode* pNode=nullptr;
		ListNode* pSlow = A;
		ListNode* pQucik = A;
		//快慢指针找到中间节点
		while (pQucik!=nullptr&&pQucik->next!=nullptr)
		{
			pQucik = pQucik->next->next;
			pSlow = pSlow->next;
			
		}
		//将中点结点后的指针反转
		pNode = pSlow->next;
		while (pNode!=nullptr)
		{
			ListNode* temp = pNode;
			pNode = pNode->next;
			temp->next = pHead;
			pHead = temp;
		}
		while (A->next!=pHead)
		{
			if (A->next->val!=pHead->val)
			{
				return false;
			}
			A = A->next;
			pHead = pHead->next;
		}
		return true;
	}
};

class PalindromeList1 {
public:
	bool chkPalindrome(ListNode* A) {
		// write code here
		if (A == nullptr || A->next == nullptr)
			return true;
		ListNode* head = nullptr;
		ListNode* node = A;
		while (node != nullptr){
			ListNode* temp = node;
			node = node->next;
			temp->next = head;
			head = temp;
		}
		while (A != nullptr&&head != nullptr){
			if (A->val != head->val){
				return false;
			}
			A = A->next;
			head = head->next;
		}
		return true;
	}
};

void print(ListNode* pHead)
{
	if (pHead==nullptr)
	{
		puts("链表为空！");
		return;
	}
	puts("链表为：");
	ListNode*pNode = pHead->next;
	while (pNode)
	{
		printf("%-d ->", pNode->val);
		pNode = pNode->next;
	}
	cout << "NULL\n";
}

ListNode* create()
{
	ListNode* pHead, *pNode, *temp;
	int x;
	pHead = pNode = (ListNode*)malloc(sizeof(ListNode));  //带头节点的链表
	printf("请输入链表数据，以0为结束标志：\n");
	scanf("%d", &x);
	while (x)
	{
		temp = (ListNode*)malloc(sizeof(ListNode));
		temp->val = x;
		pNode->next = temp;
		pNode = temp;
		scanf("%d", &x);
	}
	pNode->next = nullptr;
	return pHead;
}


int main()
{
	ListNode *pHead = create();
	print(pHead);
	PalindromeList s;
	bool val=s.chkPalindrome(pHead);
	cout << val << endl;
	return 0;
}
