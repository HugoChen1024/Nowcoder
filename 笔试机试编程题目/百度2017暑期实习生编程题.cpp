//拉姆刚开始学习英文单词，对单词排序很感兴趣。
//如果给拉姆一组单词，他能够迅速确定是否可以将这些单词排列在一个列表中，使得该列表中任何单词的首字母与前一单词的为字母相同。
//你能编写一个程序来帮助拉姆进行判断吗？
//
//输入描述 :
//
//输入包含多组测试数据。
//
//对于每组测试数据，第一行为一个正整数n，代表有n个单词。
//
//然后有n个字符串，代表n个单词。
//
//保证：
//
//2 <= n <= 200, 每个单词长度大于1且小于等于10, 且所有单词都是由小写字母组成。
//
//
//
//
//输出描述 :
//对于每组数据，输出"Yes"或"No"
//
//输入例子 :
//	 3
//	 abc
//	 cdefg
//	 ghijkl
//	 4
//	 abc
//	 cdef
//	 fghijk
//	 xyz
//
//
// 输出例子 :
//Yes
//No


#include <iostream>
using namespace std;
#include <vector>
#include <string>

int main()
{
	int n;
	while (cin>>n)
	{
		vector<string> vc(n);
		for (int i = 0; i < n;i++)
		{
			cin >> vc[i];
		}
		bool flag = true;
		for (int i = 0; i < n-1;i++)   //提出为bool的函数
		{
			int size = vc[i].size();
			if (vc[i][size-1]==vc[i+1][0])
			{
				continue;
			}
			else{
				flag = false;			
				break;
			}
			
		}
		if (flag)
		{
			cout << "Yes" << endl;
		}
		else
		{
			cout << "No" << endl;
		}
	}
	return 0;
}


//页面调度算法
//在计算机中，页式虚拟存储器实现的一个难点是设计页面调度（置换）算法。其中一种实现方式是FIFO算法。
//FIFO算法根据页面进入内存的时间先后选择淘汰页面，先进入内存的页面先淘汰，后进入内存的后淘汰。
//假设Cache的大小为2, 有5个页面请求，分别为 2 1 2 3 1，则Cache的状态转换为：(2)->(2, 1)->(2, 1)->(1, 3)->(1, 3)，其中第1, 2, 4次缺页，总缺页次数为3。
//现在给出Cache的大小n和m个页面请求，请算出缺页数。
//
//
//输入描述 :
//
//输入包含多组测试数据。
//
//对于每组测试数据，第一行两个整数n, m。
//
//然后有m个整数，代表请求页编号。
//
//保证：
//
//2 <= n <= 20, 1 <= m <= 100，1 <= 页编号 <= 200.
//
//
//
//
//输出描述:
//对于每组数据，输出一个整数，代表缺页数
//
//输入例子 :
//2 5
//2 1 2 3 1
//
//
//输出例子 :
//	 3

#include <iostream>
using namespace std;
#include<vector>

int main()
{
	int n, m;
	while (cin>>n>>m)
	{
		int times = 0;
		vector<int> vc;  //Cache的大小n ,往里面添加m个页面请求。m>n才产生页面置换
		if (m<=n)
		{
			for (int i = 0; i < m; i++)  //m次输入
			{
				bool flag = false;
				int temp;
				cin >> temp;
				for (int j = 0; j < vc.size(); j++)
				{
					if (vc[j] == temp)  //有相同的页面
					{
						flag = true;
						break;
					}
				}
				if (!flag)
				{
					vc.push_back(temp);
					times++;
				}
			}
		}
		else
		{
			for (int i = 0; i < n; i++)  //前n次输入
			{
				bool flag = false;
				int temp;
				cin >> temp;
				for (int j = 0; j < vc.size(); j++)
				{
					if (vc[j] == temp)  //有相同的页面
					{
						flag = true;
						break;
					}
				}
				if (!flag)
				{
					vc.push_back(temp);
					times++;
				}
			}
			for (int i = n; i < m; i++)  //m次输入
			{
				bool flag = false;
				int temp;
				cin >> temp;
				for (int j = 0; j < n; j++)     //能否找到提出为bool的函数，find()函数返回为iterator，可以自定义函数。
				{
					if (vc[j] == temp)  //有相同的页面
					{
						flag = true;
						break;
					}
				}
				if (!flag)
				{
					if (vc.size()==n)  //这个bug找了很久，可能前面有重复的，根本就没有装满n个。
					{
						vc.erase(vc.begin());
					}
					vc.push_back(temp);
					times++;
				}
			}
		}
		cout << times << endl;
	}
	return 0;
}


//优化好一些
#include <iostream>
#include <vector>

bool vecfind(std::vector<int>& vec, int num) {
	int len = vec.size();
	for (int i = 0; i < len; ++i){
		if (num == vec[i])
			return true;
	}
	return false;
}

int main() {
	int n, m;
	while (std::cin >> n >> m) {
		std::vector<int> vecCache;
		std::vector<int> vecPage(m);
		int cnt = 0;
		for (int i = 0; i < m; ++i) {
			std::cin >> vecPage[i];
		}
		for (int i = 0; i < m; ++i) {
			if (vecfind(vecCache, vecPage[i])) {
				continue;
			}
			else {
				if (vecCache.size() < n) {
					vecCache.push_back(vecPage[i]);
				}
				else{
					vecCache.erase(vecCache.begin());
					vecCache.push_back(vecPage[i]);
				}
				++cnt;
			}
		}

		std::cout << cnt << std::endl;
	}
	return 0;
}



//进程调度算法
//短作业优先（SJF, Shortest Job First）又称为“短进程优先”SPN(Shortest Process Next)；是对FCFS算法的改进，其目标是减少平均周转时间。
//短作业优先调度算法基于这样一种思想：
//运行时间短的优先调度；
//如果运行时间相同则调度最先发起请求的进程。
//等待时间：一个进程从发起请求到开始执行的时间间隔。
//现在有n个进程请求cpu，每个进程用一个二元组表示：(p, q), p代表该进程发起请求的时间，p代表需要占用cpu的时间。
//请计算n个进程的平均等待时间。
//
//
//输入描述 :
//
//
//输入包含多组测试数据。
//
//对于每组测试数据，第一行为一个整数n。
//
//然后有n行，每行两个整数，代表上述的二元组(p, q).
//
//保证:
//
//2 <= n <= 2000, 1 <= p <= 300, 1 <= q <= 100.
//
//
//
//
//输出描述 :
//
//	 对于每组数据，输出一个浮点数，代表平均等待时间，请保留4位有效数字
//
// 输入例子 :
//
//4
//1 4
//1 3
//1 5
//2 1
//
//
//输出例子:
//
//5.2500


//题意有错，题目中，调度的优先级：
//1)运行时间短的优先调度；
//2)如果运行时间相同则调度最先发起请求的进程。
//应当被理解为条件1优先于条件2。
//对于样例数据，在时间点1，CPU接到的任务分别为 1 3, 1 4, 1 5, 那么应该先运行1 3, 此时时间为4(不考虑抢占式调度的话）, 已经接到了调度任务2 1，接下来应该运行2 1, 最后得到的结果应该是3.5.
//若要得到5.25的结果，在运行1 3 后应该运行 1 4, 随后运行 1 5, 最后 2 1，那此时优先级描述应当为：
//1)接到任务的时间；
//2) 如果接收时间相同则调度 运行时间最短的任务。


//参考：http://www.nowcoder.com/questionTerminal/6286bfa395c44b449031254d1ebd2a53
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;
const int maxn = 2010;

struct Node {
	int id, p, q;
	Node() { }
	Node(int _id, int _p, int _q) : id(_id), p(_p), q(_q) { }
	bool operator < (const Node &nd) const {
		if (q == nd.q) return p > nd.p;
		return q > nd.q;
	}
};
Node arr[maxn];
priority_queue<Node> pq;
bool mark[maxn];

int main() {

	//freopen("aa.in", "r", stdin);
	int n;
	double total = 0.0;
	int curt;
	int mins;
	int cnt;
	int lef;
	Node tmp;
	while (scanf("%d", &n) != EOF) {
		mins = 1010;
		for (int i = 0; i < n; ++i) {
			arr[i].id = i;
			scanf("%d %d", &arr[i].p, &arr[i].q);
			mins = min(mins, arr[i].p);
		}
		lef = n;
		cnt = 0;
		total = 0.0;
		curt = mins;
		memset(mark, false, sizeof(mark));
		while (!pq.empty()) pq.pop();
		for (int i = 0; i < n; ++i) {
			if (arr[i].p == mins) {
				lef--;
				pq.push(arr[i]);
				mark[i] = true;
			}
		}
		while (cnt < n) {
			if (!pq.empty()) {
				tmp = pq.top(); pq.pop();
				cnt++;
				total += (curt - tmp.p);
				curt += tmp.q;
			}
			else {
				curt++;
			}
			if (lef > 0) {
				for (int i = 0; i < n; ++i) {
					if (mark[i]) continue;
					if (curt >= arr[i].p) { pq.push(arr[i]); lef--; mark[i] = true; }
				}
			}
		}
		printf("%.4f\n", total * 1.0 / n);
	}
	return 0;
}

typedef struct pro {
	int PRO_ID;
	int arrive_time;
	int sum_time;
	int flag;
}Pro;