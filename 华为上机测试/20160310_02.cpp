//题目描述
//
//写出一个程序，接受一个十六进制的数值字符串，输出该数值的十进制字符串。
//
//输入描述 :
//输入一个十六进制的数值字符串。
//
//
//输出描述 :
//输出该数值的十进制字符串。

#include<iostream>	
#include<string>
using namespace std;

void fun(string str)
{
	if (str.empty())
	{
		return;
	}
	int j=0;
	int result=0,n=1;
	//while (str[i++] != 'x');  //读到x的下一个字符
	int len = str.size()-1;

	while (str[len]!='x') //如果没有x，一直减下去，有错
	{
		if (str[len]<='Z'&&str[len]>='A')
			j = str[len] - 'A' + 10;  //字符转化为整形
		else
		{
			j = str[len] - '0';
		}
		result = j*n + result;
		n =n*16;
		len--;
		if (len==0)
		{
			break;
		}
	}
	cout << result << endl;
}
int main()
{
	string str;
 // 	while (cin>>str)   //死循环居然也通过了  //说在windows下输入ctrl+Z即退，有时按两次，
	//{
	//	fun(str);
	//} 

	//cin >> str;
	//while (str!=" ")   //解决死循环，貌似没有
	//{
	//	fun(str);
	//	cin >> str;
	//}



	//istream& getline(istream& is, string& str, char delim);  //返回值是istream类型，不能作为while退出的判断条件
	//istream& getline(istream& is, string& str);
	//Return Value
	//	The same as parameter is.
	getline(cin,str);
	while (str != " ")   //解决死循环,空格键退出
	{
		fun(str);
		getline(cin, str);
	}
	return 0;
}
//
//#include<iostream>
//#include <vector>
//#include <string>
//using namespace std;
//int main()
//{
//	vector<string> vect;
//	string str;
//	while (cin >> str)
//	{
//		if (str == "0")   //这种方式也可以退出
//			break;
//		vect.push_back(str);
//	}
//	return 0;
//}
