//题目描述
//
//给定n个字符串，请对n个字符串按照字典序排列。
//输入描述 :
//输入第一行为一个正整数n(1≤n≤1000), 下面n行为n个字符串(字符串长度≤100), 字符串中只含有大小写字母。
//
//
//输出描述 :
//数据输出n行，输出结果为按照字典序排列的字符串。

//本题的考察很基础，但是有一些细节问题需要注意，在C语言中应注意C语言的所有字符串的本质是以空字符'\0'结束的字符数组，
//所以在C语言中对于字符串的比较不能使用> < == 这些常规的关系运算符，而要使用C语言标准库函数中的strcmp函数对字符串进行比较，
//比较的原则就是字典顺序，在C++中，string类对> < == 这些运算符进行了重载，可以直接用来比较字符串，比较的原则依然是字典顺序。
//剩下的就是考察排序方法，常用的冒泡排序、选择排序等等都可以实现，但是借助STL更方便

#include<iostream>
using namespace std;
#include<vector>
#include<string>
#include<algorithm>
int main()
{
	int num;
	while (cin>>num)
	{
		vector<string> ve;
		string temp;
		while (num--)
		{
			//scanf("%s",temp);     //getline(cin,a);
			//以前不是看的大量输入时用scanf ,printf代替cin ,cout吗？？这里不行啊
			cin >> temp;
			ve.push_back(temp);
		}
		sort(ve.begin(),ve.end());
		for (auto it=ve.begin(); it!= ve.end(); it++)
		{
			//printf("%s\n", *it); //printf("%s", s.c_str()); //不推荐
			cout << *it << endl;
		}
	}
	return 0;
}