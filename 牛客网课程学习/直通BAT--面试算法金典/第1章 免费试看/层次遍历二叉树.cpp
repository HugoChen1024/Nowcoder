
//有一棵二叉树，请设计一个算法，按照层次打印这棵二叉树。
//给定二叉树的根结点root，请返回打印结果，结果按照每一层一个数组进行储存，所有数组的顺序按照层数从上往下，且每一层的数组内元素按照从左往右排列。保证结点数小于等于500。

#include <iostream>
using namespace std;
#include <vector>
#include<deque>
#define N 10

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
		val(x), left(NULL), right(NULL) {
	}
};

class TreePrinter {
public:
	vector<vector<int> > printTree(TreeNode* root) {
		// write code here
		vector<vector<int> > vc;
		for (int level = 0;; level++)
		{
			if (!printTreeLevel(root, level))  //巧妙地避开了访问二叉树的深度
			{
				break;
			}
			vc.push_back(res);
			res.clear();
		}
		return vc;
	}

	int  printTreeLevel(TreeNode* root, int level)//访问以root为根节点的第level层结点。失败返回0，成功返回1；
	{
		if (!root)  //只有5这个结点有孩子没有置空
		{
			return 0;
		}
		if (level == 0)
		{
			res.push_back(root->val);
			return 1;
		}
		return printTreeLevel(root->left, level - 1) + printTreeLevel(root->right, level - 1);
	}

	//二叉树的深度
	int deepth(TreeNode* root)
	{
		if (!root)
		{
			return 0;
		}
		return deepth(root->left) > deepth(root->right) ? (deepth(root->left) + 1) : (deepth(root->right) + 1);
	}
private:
	vector<int> res;

	//方法二:从根节点出发，依次将每层结点从左到右压入一个数组，并用cur记录当前访问的结点，last标记当前层的最后一个结点的下一个位置（下标从0开始），当cur==last表示当前层访问结束
public:
	//vector<vector<int> > printTree2(TreeNode* root)
	//{
	//	vector<vector<int> > res;
	//	if (!root)
	//	{
	//		return res;
	//	}
	//	vector<TreeNode*> vc;
	//	vc.push_back(root);
	//	vector<int> level;
	//	int cur = 0;
	//	int last = 1;
	//	while (cur < vc.size())
	//	{
	//		last = vc.size();
	//		while (cur < last)
	//		{
	//			level.push_back(vc[cur]->val);
	//			if (vc[cur]->left)
	//			{
	//				vc.push_back(vc[cur]->left);
	//			}
	//			if (vc[cur]->right)
	//			{
	//				vc.push_back(vc[cur]->right);
	//			}
	//			cur++;
	//		}
	//		res.push_back(level);
	//		level.clear();
	//	}
	//	return res;
	//}

	////运用队列
	//vector<vector<int> > printTree1(TreeNode* root) {
	//	vector<vector<int> > result;
	//	if (root == NULL) 
	//		return result;
	//	deque<TreeNode*> q;
	//	TreeNode* last = root;
	//	TreeNode* nlast = root;  //指向下一层的最后一个结点
	//	vector<int> tmp;
	//	q.push_back(root);
	//	while (!q.empty()){
	//		TreeNode* cur = q.front();
	//		q.pop_front();
	//		tmp.push_back(cur->val);
	//		if (cur->left) {
	//			q.push_back(cur->left);
	//			nlast = cur->left;
	//		}
	//		if (cur->right) {
	//			q.push_back(cur->right);
	//			nlast = cur->right;
	//		}
	//		if (last == cur) {
	//			result.push_back(tmp);
	//			tmp.clear();
	//			last = nlast;
	//		}
	//	}
	//	return result;
	//}
	//private:
	//	char test[] ;
	//void createBiTree(TreeNode* root)  //字符串类型的树创建方法
	//{
	//	int i = 0;
	//	char c;
	//	if (test[i]&&'#'==(c==test[i]))
	//	{
	//		root = nullptr;
	//	}
	//	else
	//	{
	//		root = new TreeNode(1);
	//		root->val = c;
	//		createBiTree(root->left);
	//		createBiTree(root->right);
	//	}
	//}

	//数字类型的树创建的方法   //所以这样方式创建还需要改进
	//生成一个结点
	TreeNode* createNode(int i)
	{
		TreeNode* q = new TreeNode(i);
		q->left = nullptr;
		q->right = nullptr;
		return q;
	}
	TreeNode* creteTree()
	{
		TreeNode* p[N]={nullptr };
		for (int i = 0; i < N;i++)
		{
			p[i] = createNode(i+1);
		}
		for (int i = 0; i < N / 2;i++)
		{
			p[i]->left = p[i * 2 + 1];
			p[i]->right = p[i * 2 + 2];
		}
		p[4]->right = nullptr;
		return p[0];
	}

public:
	int getLeafNode(TreeNode* T)
	{
		if (NULL == T)
			return 0;

		if (NULL == T->left && NULL == T->right)
			return 1;

		return getLeafNode(T->left) + getLeafNode(T->right);
	}
};

int main()
{
	TreePrinter t;
	TreeNode* T;
	T=t.creteTree();
	vector<vector<int> > vc = t.printTree(T);
	for (int i = 0; i < vc.size();i++)
	{
		for (int j = 0; j < vc[i].size();j++)
		{
			cout << vc[i][j]<<" ";
		}
		cout << endl;
	}
	return 0;
}