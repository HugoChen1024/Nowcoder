
//对于一个给定的字符串，我们需要在线性(也就是O(n))的时间里对它做一些变形。首先这个字符串中包含着一些空格，
//就像"Hello World"一样，然后我们要做的是把着个字符串中由空格隔开的单词反序，同时反转每个字符的大小写。
//比如"Hello World"变形后就变成了"wORLD hELLO"。

//输入描述:
//给定一个字符串s以及它的长度n(1≤n≤500)
//
//输出描述 :
//	 请返回变形后的字符串。题目保证给定的字符串均由大小写字母和空格构成。
//
// 输入例子 :
//"This is a sample", 16
//
//输出例子 :
//	 "SAMPLE A IS tHIS"

//
//这道题看上去不是很难，可是很多边界问题 需要考虑。
//比如：##this#is#a#sample## 返回 ##SAMPLE#A#IS#THIS##，而不是SAMPLE#A#IS#THIS。（Tips:#代表空格）
//本题的思路：首先将字符串大小写进行替换，然后反转整个字符串，最后反转每个单词，其他的不改变。
#include <iostream>
using namespace std;
#include <string>
#include <stack>
#include <vector>
class Transform {
public:
	string trans(string s, int n) {
		// write code here
		vector<char> vec;
		stack<vector<char> > sta;
		for (int i = 0; i < n;i++)
		{
			if ('Z'>=s[i]&&s[i]>='A')
			{
				s[i] = s[i] + 32;
				vec.push_back(s[i]);
				if (i == (n - 1))  //最后没有结束标志
				{
					sta.push(vec);
					vec.clear();
				}
			}
			else if ('a'<=s[i]&&'z'>=s[i])
			{
				s[i] = s[i] - 32;
				vec.push_back(s[i]);
				if (i==(n-1))
				{
					sta.push(vec);
					vec.clear();
				}
			}
			else if (s[i]==' ')
			{
				if (!vec.empty()) //为空格的情况
				{
					sta.push(vec);
					vec.clear();
				}		
				vec.push_back(s[i]);
				sta.push(vec);
				vec.clear();
			}

		}
		string result;
		while (!sta.empty())
		{
			vector<char> temp=sta.top();
			for (auto it = temp.begin(); it!= temp.end();it++)
			{
				result += *it;
			}
		//	result += ' ';
			sta.pop();
		}
		return result;
	}
};

int main()
{
	Transform t;
	string str;
	int n;
	getline(cin,str);
	cin >> n;
	//t.trans(str,n);
	cout << t.trans(str, n)<<endl;
}

//可以把反转和大小写变化分开进行。
class Transform {
public:
	string trans(string s, int n) {
		// write code here
		//大小写替换
		for (int i = 0; i < n; i++){
			if (s[i] >= 'a'&&s[i] <= 'z'){
				s[i] = toupper(s[i]);
			}
			else if (s[i] >= 'A'&&s[i] <= 'z'){
				s[i] = tolower(s[i]);
			}
		}
		//反转整个字符串
		reverse(s.begin(), s.end());
		auto pbegin = s.begin();
		auto pend = s.begin();
		while (*pend != '\0'){
			if (*pend == ' '){
				//碰到空格则反转单词
				reverse(pbegin, pend);
				pbegin = pend + 1;
			}
			++pend;
		}
		//处理边界情况，字符串末尾的单词需要反转
		reverse(pbegin, pend);
		return s;
	}
};