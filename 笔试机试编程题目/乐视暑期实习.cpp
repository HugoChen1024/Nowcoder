/*!
 * \file 乐视暑期实习.cpp
 * \date 2016/07/20 17:33
 *
 * \author ranjiewen
 * \contact: ranjiewen@outlook.com
 *
 */

//题目链接：http://www.nowcoder.com/questionTerminal/243c12aea2e14de1a05fcbb412556853?difficulty=00100&orderByHotValue=0&pos=3

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int getNum(vector<string> data, int i, string &s)
{
	int num = 0;
	int j;
	for (j = 0; j < data[i].size(); j++)
	{
		char a = data[i][j];
		if (s.find(a) == string::npos)
		{
			s.push_back(a);
			if (i == data.size() - 1)
			{
				num++;
				s.pop_back();
			}
			else
			{
				num += getNum(data, i + 1, s);
				s.pop_back();
			}
		}
	}
	//s.pop_back();
	return num;
}

int main()
{
	vector<string> data;
	int n;
	while (cin >> n)
	{
		int i = 0;
		string s = "";  
		int num = 0;
		for (int j = 0; j < n; j++)
		{
			string tmp;
			cin >> tmp;
			data.push_back(tmp);
		}
		cout << getNum(data, i, s) << endl;
		data.clear();
	}
	return 0;
}


////*将问题转化为求一棵树第n层有多少叶子节点的问题，所以使用DFS方法，只需要判断有哪些分支有n层即可*
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int res;
vector<string> vc;  //记录每种方案，有bug
string str = {};
void getNumDFS(vector<string>, vector<int>, int, int);
int main(){
	int n;
	while (cin >> n){
		res = 0;
		vector<int> visit = { 0, 0, 0, 0, 0, 0 };
		vector<string> data;
		for (int i = 0; i < n; i++){
			string tmp;
			cin >> tmp;
			data.push_back(tmp);
		}
		getNumDFS(data, visit, n, 0);
		cout << res << endl;
	}
	return 0;
}
void getNumDFS(vector<string> data, vector<int> visit, int n, int p){
	if (n == p){
		res++;
		vc.push_back(str);
		str.erase(0,n);
		return;
	}
	for (int i = 0; i < data[p].size(); i++){  //从第一层开始，依次取值
		if (visit[data[p][i] - '0'] == 0){
			visit[data[p][i] - '0'] = 1;
			char temp = data[p][i];
			str += temp;   // 可以这样用
			getNumDFS(data, visit, n, p + 1);   //p为层数，即有N层，每层取值
			visit[data[p][i] - '0'] = 0;
		}
	}
	str.clear();
}



//题目链接：http://www.nowcoder.com/questionTerminal/382b23292d4640cea476cfa7a137db51

//在最近几场魔兽争霸赛中，赫柏对自己的表现都不满意。
//为了尽快提升战力，赫柏来到了雷鸣交易行并找到了幻兽师格丽，打算让格丽为自己的七阶幻兽升星。
//经过漫长的等待以后，幻兽顺利升到了满星，赫柏很满意，打算给格丽一些小费。
//赫柏给小费是有原则的：
//1.最终给格丽的钱必须是5的倍数；
//2.小费必须占最终支付费用的5%~10 % 之间（包含边界）。
//升星总共耗费A魔卡，赫柏身上带了B魔卡，赫柏想知道他有多少种支付方案可供选择。
//注：魔卡是一种货币单位，最终支付费用 = 本该支付的 + 小费

#include<iostream>
#include<math.h>
using namespace std;
int main(){
	int A, B;
	while (cin >> A&&cin >> B){		
		////总费用的范围为   A / 0.95 <= f <= A / 0.9
		int a = ceil(A / 0.95), b = floor(A / 0.9);
		int count = 0;
		while (a%5!=0&&a<b)
		{
			a++;
		}
		for (int i = a; i <= b&&i<=B;i=i+5)
		{
			count++;
		}
		cout << count << endl;
	}
	return 0;
}


#include<iostream>
#include<math.h>
using namespace std;
int main(){
	int A, B, R;
	while (cin >> A&&cin >> B){
		////总费用的范围为   A / 0.95 <= f <= A / 0.9
		int a = ceil(A / 0.95), b = floor(A / 0.9);
		//方法一
		R = 0;
		if (a <= B){
			if (b > B){      
				R = B / 5 - a / 5;
			}
			else{
				R = b / 5 - a / 5;
			}
			if (a % 5 == 0)   //达到每次++5的功能
				R++;
		}
		cout << R << endl;
	}
	return 0;
}


#include<iostream>
#include<math.h>
using namespace std;
int main(){
	int A, B;
	while (cin >> A&&cin >> B){		
		//方法三，从小费的角度出发呢？？ 就是超时
		int start = A;
		int num = 0;
		while (start % 5 != 0 && start<B)
		{
			start++;
		}
		for (int i = start; i < B && ((start - A) <= start*0.1);i=i+5)
		{
			num++;
		}
		cout << num << endl;
	}
	return 0;
}

//题目链接：http://www.nowcoder.com/questionTerminal/2fdc144e8b5e4a9c8035bf7359a062fd?orderByHotValue=1&pos=129
//只需要按一个方向遍历一遍 利用勾股定理x*x+y*y = r*r 即可解决四分之一圆周的点 *4 即为结果

#include <iostream>
using namespace std;
#include <math.h>
int main()
{
	int S;
	while (cin>>S)
	{
		int num = 0;
		for (int i = 1; i*i <= S;i++)
		{
			int temp = S - i*i;
			int r = sqrt(temp);
			if (r*r==temp)
			{
				num++;
			}
		}
		cout << 4 * num << endl;
	}
}
