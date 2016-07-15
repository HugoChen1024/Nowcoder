/*****************************************************
* \file     SingletonPatternDemo.cpp
* \date     2016/07/13 18:20
* \author   ranjiewen
* \contact: ranjiewen@outlook.com
*****************************************************/

//有一楼梯共m级，刚开始时你在第一级，若每次只能跨上一级或者二级，要走上m级，共有多少走法？注：规定从一级到一级有0种走法。
//给定一个正整数int n，请返回一个数，代表上楼的方式数。保证n小于等于100。为了防止溢出，请返回结果Mod 1000000007的值。
//测试样例：
//3
//返回：2


#include <iostream>
using namespace  std;

//// 费波纳西数列的非递归解法
class GoUpstairs {
public:
	int countWays(int n) {
		// write code here
		/*if (n == 1)
			return 0;

			else if (n == 2)
			return 1;
			else if (n == 3)
			return 2;
			else
			return (countWays(n - 1) + countWays(n - 2)) % 1000000007;*/
		unsigned long long dp[101] = { 0 };
		dp[2] = 1;
		dp[3] = 2;
		for (int i = 4; i <= n; i++)
		{
			dp[i] = dp[i - 1] + dp[i - 2];
			if (dp[i] > 1000000007)
			{
				dp[i] = dp[i] % 1000000007;   //59以后的数就没有意义了，溢出了。
			}
		}
		return dp[n];
	}
};

int main(int argc, char* argv[])
{
	int  count = 0;
	GoUpstairs s;
	cout << s.countWays(96) << endl;
	//cout << s.dp[96] << endl;
	return 0;
}

//小东和三个朋友一起在楼上抛小球，他们站在楼房的不同层，假设小东站的楼层距离地面N米，球从他手里自由落下，每次落地后反跳回上次下落高度的一半，并以此类推知道全部落到地面不跳，求4个小球一共经过了多少米？(数字都为整数)
//给定四个整数A, B, C, D，请返回所求结果。
//测试样例：
//100, 90, 80, 70
//返回：1020


class Balls {
public:
	int calcDistance(int A, int B, int C, int D) {
		// write code here
		return 3 * (A + B + C + D);
	}

	int calcDistance(int A, int B, int C, int D) {
		int result = A + B + C + D;
		return result + distance(A) + distance(B) + distance(C) + distance(D);
	}
private:
	int distance(int n) {
		if (n <= 0)
			return 0;
		int mod = n % 2;
		return n + distance(n / 2) + mod;
	}
};
