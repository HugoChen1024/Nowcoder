//题目描述
//
//编写一个函数，计算字符串中含有的不同字符的个数。字符在ACSII码范围内(0~127)。不在范围内的不作统计。
//
//输入描述 :
//输入N个字符，字符在ACSII码范围内(0~127)。

#include<iostream>
#include<string>   //申明后才重载了cin>>符号
#include<map>
using namespace std;
void getStringNumber(string str)
{
	map<char, int> maps;
	for (size_t i = 0; i < str.size(); i++)
	{
		maps[str[i]]++;
	}
	cout << maps.size() << endl;
}
int main()
{
	std::string strOfInput;
	//gets(strOfInput);
	//cin.getline();
	//while (cin>>strOfInput)  //cin输入字符串以空格结束  eg:abc efg kjl 输出：3 3 3   但是编译器也通过了

	while (getline(cin,strOfInput))  // 接受一个字符串，可以接收空格并输出，需包含“#include<string>”
	{
		getStringNumber(strOfInput);
	}
	return 0;
}