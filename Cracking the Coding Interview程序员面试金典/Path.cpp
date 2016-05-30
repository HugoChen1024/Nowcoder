/*****************************************************
* \file Path.cpp
* \date 2016/05/30 15:03

* \问题描述：
对于一个有向图，请实现一个算法，找出两点之间是否存在一条路径。
给定图中的两个结点的指针UndirectedGraphNode* a,UndirectedGraphNode* b(请不要在意数据类型，图是有向图),请返回一个bool，
代表两点之间是否存在一条路径(a到b或b到a)。

* \问题分析：
这个题目考察的其实是有向图的遍历，图的遍历分为深度优先遍历和广度优先遍历，深度优先遍历用堆栈实现，广度优先遍历用队列实现，在该题目中给出了每个节点的子节点，所以最好用广度优先遍历。
图的广度优先遍历和树的层次遍历类似，但是不是完全相同，因为图是连通的，所以我们必须去标志那个节点被访问过，那个节点没有被访问过，最后如果全部访问完以后，还没有找到a到b的路径，则返回false。
注意知识点：
（1）图中有环，记得标记是否被访问
（2）要分别检测两个方向（a->b，b->a）


*****************************************************/
#include<iostream>
using namespace std;
#include <vector>
#include <map>
#include <queue>

struct UndirectedGraphNode
{
	int label;
	vector<struct UndirectedGraphNode*> neighbors;
	UndirectedGraphNode(int x) :label(x){}
};
class Path
{
public:
	bool checkPath(UndirectedGraphNode* a, UndirectedGraphNode* b)
	{
		return check(a, b) || check(b,a);
	}
	bool check(UndirectedGraphNode* a, UndirectedGraphNode* b)
	{
	  if (a==nullptr||b==nullptr)
	  {
		  return false;
	  }
	  if (a==b)
	  {
		  return true;
	  }
	  map<UndirectedGraphNode*, bool> mapNode;
	  queue<UndirectedGraphNode*> que;
	  que.push(a);
	  while (!que.empty())
	  {
		  UndirectedGraphNode* ptr = que.front();
		  mapNode[ptr] = true;
		  for (int i = 0; i < ptr->neighbors.size();i++)
		  {
			  if (ptr->neighbors[i]==b)
			  {
				  return true;
			  }
			  if (ptr->neighbors[i]&&mapNode[ptr->neighbors[i]]!=true)
			  {
				  que.push(ptr->neighbors[i]);
			  }
		  }
		  que.pop();
	  }
	  return false;
	}
};