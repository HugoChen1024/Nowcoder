//小易经常沉迷于网络游戏.有一次, 他在玩一个打怪升级的游戏, 他的角色的初始能力值为 a.
//在接下来的一段时间内, 他将会依次遇见n个怪物, 每个怪物的防御力为b1, b2, b3...bn.
//如果遇到的怪物防御力bi小于等于小易的当前能力值c, 那么他就能轻松打败怪物, 并 且使得自己的能力值增加bi; 
//如果bi大于c, 那他也能打败怪物, 但他的能力值只能增加bi 与c的最大公约数.那么问题来了, 在一系列的锻炼后, 小易的最终能力值为多少 ?
//
//输入描述 :
//	 对于每组数据, 第一行是两个整数n(1≤n<100000)表示怪物的数量和a表示小易的初始能力值.
//	 第二行n个整数, b1, b2...bn(1≤bi≤n)表示每个怪物的防御力
//
//
// 输出描述 :
//对于每组数据, 输出一行.每行仅包含一个整数, 表示小易的最终能力值

//#include<iostream>
//#include<vector>
//using namespace std;
//int gcd(int x, int y)
//{
//	if (y==0)
//	{
//		return 0;
//	}
//	if (x<y)
//	{
//		int temp = x;
//		x = y;
//		y = temp;
//	}
//	while (y)  //注意方法
//	{
//		int temp = y;
//		y = x%y;
//		x = temp;
//	}
//	return x;
//}
//int main()
//{
//	int monsterNumber = 0, initAbility = 0;
//	//vector<int> monster;
//	while (cin>>monsterNumber>>initAbility)
//	{
//		int monsterDefence;
//		for (size_t i = 0; i < monsterNumber; i++)
//		{
//			cin >> monsterDefence;
//		//	monster.push_back(monsterDefence);
//			if (initAbility>=monsterDefence)
//			{
//				initAbility += monsterDefence;
//			}
//			else
//			{
//				initAbility += gcd(initAbility,monsterDefence);
//			}
//		}
//		cout << initAbility << endl;
//	}
//	return 0;
//}

//
//兰博教训提莫之后, 然后和提莫讨论起约德尔人, 谈起约德尔人, 自然少不了一个人, 那 就是黑默丁格------约德尔人历史上最伟大的科学家.提莫说, 
//黑默丁格最近在思考一个问题:黑默丁格有三个炮台, 炮台能攻击到距离它R的敌人(两点之间的距离为两点连续的距离, 
//例如(3, 0), (0, 4)之间的距离是5), 如果一个炮台能攻击 到敌人, 那么就会对敌人造成1×的伤害.黑默丁格将三个炮台放在N*M方格中的点上, 
//并且给出敌人 的坐标.问 : 那么敌人受到伤害会是多大 ?
//
//输入描述 :
//	 第一行9个整数, R, x1, y1, x2, y2, x3, y3, x0, y0.R代表炮台攻击的最大距离, (x1, y1), (x2, y2),
//	 (x3, y3)代表三个炮台的坐标.(x0, y0)代表敌人的坐标.
//
//
// 输出描述 :
//	  输出一行, 这一行代表敌人承受的最大伤害, (如果每个炮台都不能攻击到敌人, 输出0×)

//#include<iostream>
//#include<math.h>
//using namespace std;
//int main()
//{
//	int r, x[4], y[4],result; //  //赋值放在外面通不过
//	while (cin>>r)
//	{
//		result = 0;
//		for (size_t i = 0; i < 4; i++)
//		{
//			cin >> x[i];
//			cin >> y[i];
//		}
//		for (size_t i = 0; i < 3; i++)
//		{
//			if (sqrt((x[i] - x[3])*(x[i] - x[3]) + (y[i] - y[3])*(y[i] - y[3]))<=r)
//			{
//				result++;
//			}
//		}
//		cout << result << "x" << endl;
//	}
//
//	return 0;
//}

//在N*M的草地上, 提莫种了K个蘑菇, 蘑菇爆炸的威力极大, 兰博不想贸然去闯, 而且蘑菇是隐形的.只 
//有一种叫做扫描透镜的物品可以扫描出隐形的蘑菇, 于是他回了一趟战争学院, 买了2个扫描透镜, 一个 
//扫描透镜可以扫描出(3 * 3)方格中所有的蘑菇, 然后兰博就可以清理掉一些隐形的蘑菇.问:兰博最多可以清理多少个蘑菇 ?
//
//输入描述 :
//第一行三个整数 : N, M, K, (1≤N, M≤20, K≤100), N, M代表了草地的大小;
//接下来K行, 每行两个整数x, y(1≤x≤N, 1≤y≤M).代表(x, y)处提莫种了一个蘑菇.
//一个方格可以种无穷个蘑菇.
//
//输出描述:
//输出一行, 在这一行输出一个整数, 代表兰博最多可以清理多少个蘑菇.


//解析一下这道题的已知的条件：
//
//草地大小为N*M——二维数组为N*M
//一个方格可以有多个蘑菇——数组元素的值在[0, K]区间内
//透镜检查范围为3 * 3——每次检查3 * 3的方格有多少蘑菇
//两个透镜——扫描两次，且有先后问题（下面详解）
//故这道题的解答方法如下：
//(1)读入数据N，M，K
//(2)初始化土地
//(3)使用第一块透镜扫描土地第一个3 * 3方格，并且将该方格的所有蘑菇数减1（空的不减），同时记录采集的蘑菇数mushroom1
//(4)在第(3)步的基础上，使用第二块透镜扫描土地的所有个3 * 3方格，每扫描完一个3 * 3方格，记录当前方格的蘑菇数mushroom2，注意不用再减1，计算当前mushroom1 + mushroom2    //但是不知道为什么
//(5)重复(3)(4)，直到使用第一块透镜扫描完所有的土地
//(6)输出mushroom1 + mushroom2的最大值
//

//问最多可清理多少个蘑菇就是求二维数组中哪一块（3 * 3）区域中的蘑菇数最多。
//有两个透镜，那么最多可清理的蘑菇数就是第一个透镜最多清理的加上第二个透镜
//最多清理的（将求最多清理蘑菇数写成函数）。
//需要注意的是对于每个方格如果其中有多个蘑菇那么一次扫描只能清理掉一个蘑菇。
//这要求我们在求出第一个最优解后要对二维数组中的相应方格中的蘑菇数进行减1操作。
//注意：第一块透镜和第二块透镜扫描的3 * 3方格之间没有任何关系，且透镜只能知道该方格有没有蘑菇，而不知道有几块蘑菇
#include <iostream>
#include <vector>
using namespace std;
int main()
{
	//input data
	int n, m, k;
	while (cin >> n >> m >> k){
		if (n < 3) n = 3;
		if (m < 3) m = 3;
		//initialize ground
		vector<vector<int> > ground(n, vector<int>(m, 0)); //n*m的二维vector，所有元素为0
		for (int i = 0; i<k; i++){
			int x, y;
			cin >> x >> y;
			ground[--x][--y]++;
		}

		int mushroomNum(0), mushroom1, mushroom2;
		//first scan
		for (int i = 0; i<n - 2; i++)
		for (int j = 0; j<m - 2; j++)
		{
			mushroom1 = 0;
			vector<vector<int> > groundNew = ground;//copy
			for (int row = i; row<i + 3; row++)
			for (int col = j; col<j + 3; col++)
			if (groundNew[row][col] > 0){
				groundNew[row][col]--;  //当前方格减一
				mushroom1++; //可清理的蘑菇数
			}
			//second scan
			for (int i = 0; i<n - 2; i++)
			for (int j = 0; j<m - 2; j++)
			{
				mushroom2 = 0;
				for (int row = i; row<i + 3; row++)
				for (int col = j; col<j + 3; col++)
				if (groundNew[row][col] > 0)
					mushroom2++;
				if (mushroomNum < mushroom1 + mushroom2)
					mushroomNum = mushroom1 + mushroom2;
			}
		}
		cout << mushroomNum << endl;
	}
	return 0;
}
