//题目描述
//
//编写一个函数，确定需要改变几个位，才能将整数A转变成整数B。
//给定两个整数int A，int B。请返回需要改变的数位个数。
//测试样例：
//10, 5
//返回：4


//思路：A 需要变换 多少位 才能得到B，位变换无非就是0 - 1, 1 - 0的过程所以，A和B之间 有多少的不同的0 - 1, 1 - 0的变换就有需要多少位的变换，
//由于异或操作是 相同为0 不同为1 也即1 - 0, 0 - 1的结果为1，也就是转换成A^B之后 1 的个数求解；--->问题转化

class Transform {
public:
	int calcCost(int A, int B) {
		// write code here
		int res = A ^ B;
		int count = 0;
		while (res != 0)
		{
			if ((res & 1) != 0)
			{
				count++;
			}
			res >>= 1;
		}
		return count;
	}

	int calcCost(int A, int B) {
		// write code here
		int res = A ^ B;
		int count = 0;
		while (res != 0)
		{
			count++;
			//去掉最后一位的1 例如 1111 & （1111-1） = 1110 将最后一位1 去掉
			res &= (res - 1);
		}
		return count;
	}
};