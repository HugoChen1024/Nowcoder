
//题目描述
//
//开发一个坐标计算工具， A表示向左移动，D表示向右移动，W表示向上移动，S表示向下移动。从（0, 0）点开始移动，从输入字符串里面读取一些坐标，并将最终输入结果输出到输出文件里面。
//
//输入：
//
//合法坐标为A(或者D或者W或者S) + 数字（两位以内）
//
//坐标之间以; 分隔。
//
//非法坐标点需要进行丢弃。如AA10;  A1A;  $%$;  YAD; 等。
//
//下面是一个简单的例子 如：
//
//A10; S20; W10; D30; X; A1A; B10A11;; A10;
//
//处理过程：
//
//起点（0, 0）
//
//+ A10 = （ - 10, 0）
//
//+ S20 = (-10, -20)
//
//+ W10 = (-10, -10)
//
//+ D30 = (20, -10)
//
//+ x = 无效
//
//+ A1A = 无效
//
//+ B10A11 = 无效
//
//+ 一个空 不影响
//
//+ A10 = (10, -10)
//
//
//
//结果 （10， - 10）

#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main()
{
	string str;
	//getline(cin,str);
	while (getline(cin, str))
	{
		vector<string> ve;
		string sub;
		int pos=0;//初始化
		while (pos<str.size())
		{
			if (str[pos] == ';')
			{
				ve.push_back(sub);
				sub.clear();
			}
			else
			{
				sub += str[pos];
			}
			pos++;
		}
		int xx = 0, yy = 0;//可以定义为结构体
		for (int i = 0; i<ve.size(); i++)
		{
			int flag = true;
			string t = ve[i];
			if (t.length() == 0 || t.length() == 1 || t.length()>3) continue;
			switch (t[0])
			{
			case 'W':
				for (int i = 1; i < t.length(); i++)
				{
					if (t[i] >= '0'&&t[i] <= '9');
					else
					{
						flag = false;
						break;
					}
				}
				if (flag == false)
				{
					break;
				}
				else
				{
					int temp = atoi(&t[1]);  //atoi是ASCII to integer 的缩写，是把字符串转换成长整型数的一种函数  int atoi(const char *nptr);
					yy += temp;
				}
				break;
			case 'A':
				for (int i = 1; i < t.length(); i++)
				{
					if (t[i] >= '0'&&t[i] <= '9');
					else
					{
						flag = false;
						break;
					}
				}
				if (flag == false)
				{
					break;
				}
				else
				{
					int temp = atoi(&t[1]);
					xx -= temp;
				}
				break;
			case 'S':

				for (int i = 1; i < t.length(); i++)
				{
					if (t[i] >= '0'&&t[i] <= '9');
					else
					{
						flag = false;
						break;
					}
				}
				if (flag == false)
				{
					break;
				}
				else
				{
					int temp = atoi(&t[1]);
					yy -= temp;
				}
				break;

			case 'D':
				for (int i = 1; i < t.length(); i++)
				{
					if (t[i] >= '0'&&t[i] <= '9');
					else
					{
						flag = false;
						break;
					}
				}
				if (flag == false)
				{
					break;
				}
				else
				{
					int temp = atoi(&t[1]);
					xx += temp;
				}
				break;
			default:
				break;
			}
		}
		cout << xx << "," << yy << endl;
		ve.clear();
	}
	return 0;
}