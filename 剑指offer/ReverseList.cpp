//题目描述
//
//输入一个链表，反转链表后，输出链表的所有元素。

struct ListNode
{
	int val;
	struct ListNode *next;
	ListNode(int x) :val(x), next(nullptr){}
};

//思路
//在反转链表的时候，我们很容易想到让当前结点的next指向前一个结点，
//但是这样做了之后这个节点原本next所指的结点就找不回了，所以每次我们都要保存新的前一结点，
//当前结点和下一结点三个指针，只要下一结点为空，那么我们就到了原本结点的尾部，这时正是新链表的头部
class Solution {
public:
	ListNode* ReverseList(ListNode* pHead) {

		ListNode *current = pHead;
		ListNode *pre = nullptr;
		ListNode *pNewNode = nullptr;
		if (pHead == nullptr)
		{
			return nullptr;
		}
		while (current != nullptr)  //当前结点不为空
		{
			ListNode *pnext = current->next; //当前结点的后继
			if (pnext == nullptr)
			{
				pNewNode = current;  //最后结点，即反转链表的头节点
			}
			current->next = pre; //当前结点的后继转为前驱
			pre = current;  //前驱转为当前结点
			current = pnext;  //当前结点向后移
		}
		return pNewNode;
	}
};

//1、三个指针在链表上同时滑动，比较容易想到但是编码略复杂
class Solution {
public:
	ListNode* ReverseList(ListNode* pHead) {
		if (pHead == nullptr) return nullptr;
		if (pHead->next == nullptr) return pHead;

		ListNode *pBefore = pHead, *p = pHead->next, *pAfter = p->next;
		while (pAfter) {
			p->next = pBefore; // reverse
			pBefore = p;
			p = pAfter;
			pAfter = pAfter->next;
		}
		p->next = pBefore; //完成最后一个结点的前驱
		pHead->next = nullptr; //尾结点后继为空
		return p;
	}
};

//2、从原链表的头部一个一个取节点并插入到新链表的头部
class Solution {
public:
	ListNode* ReverseList(ListNode* pHead) {
		if (pHead == nullptr) return nullptr;
		ListNode* head = pHead;
		pHead = pHead->next;
		head->next = nullptr; //此时的head为尾结点
		while (pHead) {
			ListNode *next = pHead->next;
			pHead->next = head;
			head = pHead; //
			pHead = next;
		}
		return head;
	}
};

//使用一个栈来解决问题，C++

#include<stack>
using namespace std;
class Solution {
public:
	ListNode* ReverseList(ListNode* pHead) {
		if (pHead == nullptr || pHead->next == nullptr)
		{
			return pHead;
		}
		ListNode * p = pHead;
		ListNode * newHead;
		stack<ListNode *> stack1;
		while (p->next != NULL)
		{
			stack1.push(p);
			p = p->next;
		}
		newHead = p;
		while (!stack1.empty())
		{
			p->next = stack1.top();
			p = p->next;
			stack1.pop();
		}
		p->next = NULL;
		return newHead;
	}
};


//题目描述
//
//输入一个链表，从尾到头打印链表每个节点的值。
//输入描述 :
//输入为链表的表头
//
//
//输出描述 :
//输出为需要打印的“新链表”的表头
#include<vector>
class Solution {
public:
	vector<int> printListFromTailToHead(struct ListNode* head) {

		//std::stack<ListNode*> nodes;

		// ListNode *pNode = head;
		// while(pNode != NULL)
		// {
		//      nodes.push(head);
		//      head = head->next;
		// }

		//  while(!nodes.empty())
		//  {
		//     head = nodes.top();
		//     printf("%d\t" ,head->val);
		//     nodes.pop();
		//  }

		vector<int> dev1;
		if (head != NULL)
		{
			if (head->next != NULL)
			{
				dev1 = printListFromTailToHead(head->next);
			}
			dev1.push_back(head->val);
		}
		return dev1;

	}
};

class Solution {
public:
	vector<int> printListFromTailToHead(struct ListNode* head) {
		//利用栈的逆序输出特性       
		stack<int> stack;
		vector<int> vector;
		struct ListNode *p = head;
		if (head != NULL) {
			stack.push(p->val);
			while ((p = p->next) != NULL) {
				stack.push(p->val);
			}
			while (!stack.empty()) {
				vector.push_back(stack.top());
				stack.pop();
			}
		}
		return vector;
	}

};

/***
*从原理上来说，借助栈会使得问题的解决思路非常简单明了。
*注意函数的返回类型是int类型的vector
*/
class Solution {
public:
	vector<int> printListFromTailToHead(struct ListNode* head)
	{
		vector<int> vec;         //声明一个vector存放Node的int类型的val值
		std::stack<ListNode *>nodes;
		ListNode *pNode = head;
		//遍历入栈
		while (pNode != NULL)
		{
			nodes.push(pNode);    //遍历所有节点，将结点压入栈中
			pNode = pNode->next;
		}
		//遍历出栈
		while (!nodes.empty())
		{
			pNode = nodes.top();        //定义的结点指针始终指向栈顶，取出栈顶结点的val值存入到定义的vec中，然后弹出栈顶元素。由栈顶往栈底遍历
			vec.push_back(pNode->val);
			nodes.pop();
		}
		return vec;    //返回值为int型的vector
	}
};