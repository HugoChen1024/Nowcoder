
//题目描述
//
//有两个用链表表示的整数，每个结点包含一个数位。这些数位是反向存放的，也就是个位排在链表的首部。编写函数对这两个整数求和，并用链表形式返回结果。
//给定两个链表ListNode* A，ListNode* B，请返回A + B的结果(ListNode*)。



struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}
};
class Plus {
public:
	ListNode* plusAB(ListNode* a, ListNode* b) {
		// write code here
		if (a==nullptr&&b!=nullptr)
		{
			return b;
		}
		else if (a!=nullptr&&b==nullptr)
		{
			return a;
		}
		else if (a==nullptr&&b==nullptr)
		{
			return nullptr;
		}
		else
		{
			ListNode *cHead = new ListNode(-1);
			ListNode *c = cHead;
			while (a!=nullptr&&b!=nullptr)
			{
				int temp = 0,carry = 0;
				if (a->val+b->val<10)
				{
					temp = a->val + b->val+carry;
				}
				else
				{
					int temp = (carry+a->val + b->val) % 10;
					carry = (carry + a->val + b->val) / 10;
				}
				ListNode *tmp = new ListNode(temp);
				c->next = tmp;
				c = c->next;
				a = a->next;
				b = b->next;
			}
			if (a||b)
			{
				c->next = a;
				c->next = b;
			}
			c->next = nullptr;

			return cHead->next;
			delete cHead;
		}		
	}
};

//本题的思路很简单，按照小学数学中学习的加法原理从末尾到首位，对每一位对齐相加即可。技巧在于如何处理不同长度的数字，
//以及进位和最高位的判断。这里对于不同长度的数字，我们通过将较短的数字补0来保证每一位都能相加。

ListNode* plusAB(ListNode* a, ListNode* b) {
	int carry = 0;
	ListNode *retHead = new ListNode(0);
	ListNode *p = retHead;
	while (a || b || carry) {
		int vala = a ? a->val : 0;
		int valb = b ? b->val : 0;
		int val = (vala + valb + carry) % 10;
		carry = (vala + valb + carry) / 10;  //进位
		ListNode *tmp = new ListNode(val);
		p->next = tmp;
		p = p->next;
		a = a ? a->next : nullptr;
		b = b ? b->next : nullptr;
	}
	p->next = nullptr;
	return retHead->next;
}