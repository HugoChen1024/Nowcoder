//输入描述:
//输入的第 1 行，为两个正整数，用一个空格隔开：N m
//（其中 N （ <32000 ）表示总钱数， m （ <60 ）为希望购买物品的个数。）
//
//从第 2 行到第 m + 1 行，第 j 行给出了编号为 j - 1 的物品的基本数据，每行有 3 个非负整数 v p q
//
//（其中 v 表示该物品的价格（ v<10000 ）， p 表示该物品的重要度（ 1 ~5 ）， q 表示该物品是主件还是附件。如果 q = 0 ，
//                表示该物品为主件，如果 q>0 ，表示该物品为附件， q 是所属主件的编号）
//
//输出描述 :
//输出文件只有一个正整数，为不超过总钱数的物品的价格与重要度乘积的总和的最大值（ <200000 ）。


/* 算法基本思想：

利用动态规划思想 ，子问题为：f[i][v]表示前i件物品恰放入一个容量为v的背包可以获得的最大价值。

其状态转移方程是：f[i][v]=max{f[i-1][v],f[i-1][v-c[i]]+w[i]}    //这个方程非常重要，基本上所有跟背包相关的问题的方程都是由它衍生出来的。

解释一下上面的方程：“将前i件物品放入容量为v的背包中”这个子问题，如果只考虑第i件物品放或者不放，那么就可以转化为只涉及前i-1件物品的问题，即1、如果不放第i件物品，则问题转化为“前i-1件物品放入容量为v的背包中”；2、如果放第i件物品，则问题转化为“前i-1件物品放入剩下的容量为v-c[i]的背包中”(此时能获得的最大价值就是f [i-1][v-c[i]]再加上通过放入第i件物品获得的价值w[i])。则f[i][v]的值就是1、2中最大的那个值。

（注意：f[i][v]有意义当且仅当存在一个前i件物品的子集，其费用总和为v。所以按照这个方程递推完毕后，最终的答案并不一定是f[N] [V]，而是f[N][0..V]的最大值。） */

//动态规划，(0,1)背包问题
#include<iostream>
using namespace std;

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct InputBuf
{
	int price;
	int weight;
	int type;
};

struct InputBuf inputBuf[60];
int sum_money = 0;
int sum_num = 0;

int countMaxvalue(int index, int money, int f)
{
	int a = 0, b = 0;
	if (index >= sum_num) return 0;
	if (inputBuf[index].type == 0)  //主件
	{
		if (money >= inputBuf[index].price)
		{
			a = countMaxvalue(index + 1, money - inputBuf[index].price, 1) + inputBuf[index].price * inputBuf[index].weight;  //买第index件物品的附件
			b = countMaxvalue(index + 1, money, 0);    //买主件
			return a > b ? a : b;
		}
		else
			return countMaxvalue(index + 1, money, 0);
	}
	else if ((inputBuf[index].type != 0) && (f == 1))  //附件，且主件必须买
	{
		if (money >= inputBuf[index].price)
		{
			a = countMaxvalue(index + 1, money - inputBuf[index].price, f) + inputBuf[index].price * inputBuf[index].weight;
			b = countMaxvalue(index + 1, money, f);
			return a > b ? a : b;
		}
	}
	else
	{
		return countMaxvalue(index + 1, money, f);
	}
	return 0;
}



int main(void)
{
	int i = 0;
	scanf("%d %d", &sum_money, &sum_num);
	for (i = 0; i < sum_num; i++)
	{
		scanf("%d %d %d", &inputBuf[i].price, &inputBuf[i].weight, &inputBuf[i].type);
	}
	printf("%d", countMaxvalue(0, sum_money, 1));
	return 0;
}