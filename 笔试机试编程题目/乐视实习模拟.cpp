//输入字符串，统计某一字符出现的次数

#include<iostream>
using namespace  std;
#include<string>

int main()
{
	string str;
	while (getline(cin,str))
	{
		char ch;
		int times = 0;
		cin >> ch;
		for (int i = 0; i < str.size();i++)
		{
			if (str[i]==ch)
			{
				times++;
			}
		}
		cout << times<<endl;
	}
	return 0;
}


#include<iostream>
#include<string>
using namespace std;
int main()
{
	string str;
	while (getline(cin, str))
	{
		char s;
		cin >> s;
		int count = 0;
		for (int i = 0; i < str.size(); i++)
		{
			if (s == str[i])
				count++;
		}
		cout << count << endl;
		cin.ignore();
	}
}

//下面有问题
//while (getline(cin, str))
//cin >> s
//循环的时候会出问题，第二次循环读不出s，后面加上一个cin.ignore()就好了，给所有出现此问题的人。。


//计算字符串最后一个单词的字符数

#include <string>
#include <iostream>
using namespace std;
int main()
{
	//cout << "请输入字符串：";
	string str;
	int count = 0;
	getline(cin, str);
	for (int i = str.size()-1; i >=0; i--)
	{

		if (str[i] == ' ')
			break;
		else
			count++;
	}
	cout << count << endl;
	//	cout << str.size();
	return 0;
}

// C++
//有些同学的答案没考虑到末尾有空格的情况，对于末尾有空格的都输出为0了。
//“hello world     ”依然输出5.

#include<iostream>
#include<string>
using namespace std;
int main()
{
	string s;
	while (getline(cin, s)){
		int n = 0, flag = 1;
		for (int i = s.length() - 1; i >= 0; --i){//倒着计算
			if (flag && s[i] == ' '){//如果末尾有空格，先清除末尾空格
				continue;
			}
			else if (s[i] != ' '){
				flag = 0;
				++n;
			}
			else{
				break;
			}
		}
		cout << n << endl;
	}
	return 0;
}


//输出某一正整数的所有公因数
//质数因子

#include<iostream>
using namespace std;
int main()
{
	int N;
	while (cin>>N)
	{
		int i = 2;
		while (N!=1)
		{			
			if (N%i==0)
			{
				N = N / i;
				cout << i << " ";
				continue;
			}
			i++;	
		}
		cout << endl;
	}
	return 0;
}

//质因数的个数


//