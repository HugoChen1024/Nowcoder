//利用字符重复出现的次数，编写一个方法，实现基本的字符串压缩功能。比如，字符串“aabcccccaaa”经压缩会变成“a2b1c5a3”。
//若压缩后的字符串没有变短，则返回原先的字符串。
//给定一个string iniString为待压缩的串(长度小于等于3000)，保证串内字符均由大小写英文字母组成，返回一个string，
//为所求的压缩后或未变化的串。
#include<iostream>
using namespace std;
#include<string>
#include<sstream>
class Zipper {
public:
	string zipString(string iniString) {
		// write code here
		string result;
		int count = 1;
		for (size_t i = 0; i < iniString.size(); i++)
		{
			while (iniString[i] == iniString[i + 1]&&(i+1)<iniString.size())
			{
				i++;
				count++;
			}
			result.push_back(iniString[i]);  //result+=iniString[i];
			/*stringstream ss;
			string temp;
			ss << count;
			ss >> temp;*/
			//result.push_back(temp);
			result += to_string(count);			
			count = 1;
		}
		if (iniString.size()<=result.size())
		{
			return iniString;
		}
		else 
		    return result;
	}
};

void main()
{
	Zipper z;
	string str;
	str=z.zipString("aabcccccaaa");
	cout << str << endl;

}