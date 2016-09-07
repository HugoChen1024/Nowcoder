//题目描述
//
//有一个正整数，请找出其二进制表示中1的个数相同、且大小最接近的那两个数。(一个略大，一个略小)
//给定正整数int x，请返回一个vector，代表所求的两个数（小的在前）。保证答案存在。
//测试样例：
//2
//返回：[1, 4]

//
//思路：
//取得略大的数：
//c0 是拖尾0的个数，c1是紧邻拖尾0左方连续位为1的个数， p为最右边但非拖尾的0 等于 c0 + c1
//1 把位p置为1
//2 将p右方所有位置为零  //（1,2的快速做法就是将拖尾0变为1，然后加1）
//3 在右方插入c1 - 1 个1
//取得略小的数：
//1 c1是拖尾1的个数， c0是紧邻拖尾1的左方一连串0的个数，p为最右边但非拖尾的1 等于c0 + c1
//2 把位p置为0           // (1,2的快速版本就是将拖尾1置为0，然后减1)
//3 将p右方所以位置清零
//在p的紧邻右方插入c1 + 1个1

#include <iostream>
using namespace std;
#include <vector>
#include <math.h>
class CloseNumber{
public:
	vector<int> getCloseNumber(int x) {
		// write code here
		vector <int> result;
		int c01 = 0;//拖尾0的个数
		int c11 = 0;//拖尾0左方连续全为1的个数

		int c1 = 0;//拖尾1的个数
		int c0 = 0;//拖尾1左方全为0的位个数
		int c = x, d = x;//临时变量
		//分别求取max
		while (((c & 1) == 0) && (c != 0)){
			c01++;
			c >>= 1;
		}
		while ((c & 1) == 1){
			c11++;
			c >>= 1;
		}
        //min
		while ((d & 1) == 1){
			c1++;
			d >>= 1;
		}
		while (((d & 1) == 0) && (d != 0)){
			c0++;
			d >>= 1;
		}

		result.push_back((x - (1 << (c1)) - (1 << (c0 - 1)) + 1));   //min
		result.push_back((x + (1 << (c11 - 1)) + (1 << c01) - 1));   //max
		return result;
	}

	 int findNext(int a){
		//c0是尾部0的个数， c1是0左方全为1的个数
		/*
		1,将index位p置为1；
		2,将index位从0到p-1清零
		（1,2的快速做法就是将拖尾0变为1，然后加1）
		3,将index位0到c1-2位置为1
		*/
		int c0 = 0, c1 = 0;
		int temp = a;
		while ((temp & 1) == 0 && temp != 0){
			c0++;
			temp >>= 1;
		}

		while ((temp & 1) == 1){
			c1++;
			temp >>= 1;
		}
		//判断是否没有更大的数
		if (c0 + c1 == 31 || c0 + c1 == 0){
			return -1;
		}
		int p = c0 + c1;//index为p的位置，此时p的位置肯定是0
		//1,2的快速版
		a += pow(2, c0);  //2^p-2^c1-....

		//3,将0到c1-2位置为1
		a += pow(2, c1 - 1) - 1;
		return a;

	}

	 int findPre(int b){
		//c1是尾部1的个数，c0是尾部1左方全为0的个数
		/*
		1,将index位p清零
		2,将p右边所有的位都置为1
		(1,2的快速版本就是将拖尾1置为0，然后减1)
		3,将位0到位c0-2清零
		*/
		int c1 = 0, c0 = 0;
		int temp = b;
		while ((temp & 1) == 1){
			c1++;
			temp >>= 1;
		}
		while ((temp & 1) == 0 && temp != 0){
			c0++;
			temp >>= 1;
		}

		int p = c0 + c1; //p位肯定为1
		//1,2
		b -= pow(2, c1) - 1;
		b -= 1;
		b -= pow(2, c0 - 1) - 1;
		return b;
	}
};

int main()
{
	CloseNumber c;
	vector<int> vc=c.getCloseNumber(14);
	return 0;
}