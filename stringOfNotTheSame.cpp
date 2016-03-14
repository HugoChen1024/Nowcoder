//请实现一个算法，确定一个字符串的所有字符是否全都不同。这里我们要求不允许使用额外的存储结构。
//给定一个string iniString，请返回一个bool值, True代表所有字符全都不同，False代表存在相同的字符。
//保证字符串中的字符为ASCII字符。字符串的长度小于等于3000。
#include<iostream>
#include<algorithm>
using namespace std;


//1）哈希法首先char类型判断重复，用hash数组最方便，只需要256个bool类型即可，O(n)的时间（其实只要判断前257个就行了O(1)，抽屉原理），但是题目要求不能使用额外的存储结构，那么这个方法KO掉。
//2）遍历那么只能用两层for循环遍历，时间复杂度为O(n*n)，但是根据抽屉原理，没必要遍历到N，只需要遍历到前257就够了，如果N<257就遍历到N，所以时间复杂度其实为O(1)!!!
//3）排序既然题目要求不能使用额外空间，而参数列表没有const或引用，那么就可以对字符串排序，然后再判断，需要O（nlogn)排序，然后再遍历一遍O(n)。其实也没必要全都排序，只需前257个，同抽屉原理。
//4）Parition基于快速排序的partition，可以边排序边找重复，也即是每次partition之后，判断中间key元素与两边元素是否相同，相同则返回false，不同再进行下一轮partition.时间复杂度也是O(nlongn)，但要比排序速度快。

class Different {
public:
	bool checkDifferent(string iniString) {
		// write code here
		if (iniString.empty())
		{
			return false;
		}
		sort(iniString.begin(),iniString.end() );
		for (size_t i = 0; i < iniString.size(); i++)
		{
			if (i<iniString.size()-1&&iniString[i]==iniString[i+1])
			{
				return false;
			}
		}
		return true;
	}
};