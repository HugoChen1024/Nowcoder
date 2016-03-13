//题目描述
//
//数据表记录包含表索引和数值，请对表索引相同的记录进行合并，即将相同索引的数值进行求和运算，输出按照key值升序进行输出。
//
//输入描述 :
//先输入键值对的个数
//然后输入成对的index和value值，以空格隔开
//
//
//输出描述 :
//输出合并后的键值对（多行）

//#include<iostream>
//#include<map>
//using namespace std;
//
//int main(int, char**){
//	int count;
//	cin >> count;
//	int a, b;
//	map<int, int> maps;
//	for (int i = 0; i != count; i++){
//		cin >> a >> b;
//		maps[a] += b;
//	}
//	typedef map<int, int>::iterator Iter;
//	for (Iter iter = maps.begin(); iter != maps.end(); iter++){
//		cout << iter->first << " " << iter->second << "\n";
//	}
////	getchar();
////	getchar();
//	return 0;
//}

#include<iostream>
#include<map>
using namespace std;
int main()

{
	int value, key;
	int n;
	while (cin>>n)
	{
		map<int, int> maps;
		for (size_t i = 0; i < n; i++)
		{
			cin >> key >> value;
			pair<map<int, int>::iterator, bool > rel = maps.insert(make_pair(key,value));
			if (!rel.second) //如果插入key存在，则累加value
			{
				rel.first->second += value;
			}
		}
		for (auto it = maps.begin(); it !=maps.end(); it++)
		{
			cout << (*it).first << " " << (*it).second << endl;
		}
	}
	system("pause");
	return 0;
}


//#include <iostream>
//#include <map>
//#include <set>
//using namespace std;
//int main()
//{	int inSum;
//	while (cin >> inSum)
//	{
//		int key, value;
//		set<int> si;
//		map<int, int> mii;
//		while (inSum--)
//		{
//			cin >> key;
//			si.insert(key);
//			cin >> value;
//			mii[key] = mii[key] + value;
//		}
//		set<int>::iterator it;
//		for (it = si.begin(); it != si.end(); it++)
//		{
//			cout << *it << " " << mii[*it] << endl;
//		}
//	}
//	return 0;
//
//}