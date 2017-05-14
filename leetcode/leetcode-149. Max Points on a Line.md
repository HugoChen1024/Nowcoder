## 题目表述

- Given n points on a 2D plane, find the maximum number of points that lie on the same straight line.

## 分析

- 暴力枚举法。两点决定一条直线， n 个点两两组合，可以得到 1/2n(n + 1) 条直线，对每一条直线，判断 n 个点是否在该直线上，从而可以得到这条直线上的点的个数，选择最大的那条直线返回。复杂度 O(n3)。

- 上面的暴力枚举法以“边”为中心，再看另一种暴力枚举法，以每个“点”为中心，然后遍历剩余点，找到所有的斜率，如果斜率相同，那么一定共线对每个点，用一个哈希表， key 为斜率， value为该直线上的点数，计算出哈希表后，取最大值，并更新全局最大值，最后就是结果。时间复杂度O(n2)，空间复杂度 O(n)

- 注意这道题的编译精度
```
分析：
任意一条直线都可以表述为
y = ax + b
假设，有两个点(x1,y1), (x2,y2)，如果他们都在这条直线上则有
y1 = kx1 +b
y2 = kx2 +b
由此可以得到关系，k = (y2-y1)/(x2-x1)。即如果点c和点a的斜率为k, 而点b和点a的斜率也为k，可以知道点c和点b也在一条线上。
取定一个点points[i], 遍历其他所有节点, 然后统计斜率相同的点数，并求取最大值即可

```
## AC代码

```C++

#include <iostream>
using namespace std;
#include <vector>
#include <unordered_map>

#define max(a,b)    (((a) > (b)) ? (a) : (b))

//Definition for a point.
struct Point {
	int x;
	int y;
	Point() : x(0), y(0) {}
	Point(int a, int b) : x(a), y(b) {}
};


class Solution {
public:
	int maxPoints(vector<Point> &points)
	{
		if (points.size()<3)
			return points.size();
		int result = 0;
		unordered_map<double, int> slope_count;

		for (int i = 0; i<points.size() - 1; i++)
		{
			slope_count.clear();
			int samePointNum = 0; //与i重合的点
			int point_max = 1; //和i共线的最大点数
			for (int j = i + 1; j<points.size(); j++)
			{
				double slope; //斜率
				if (points[i].x == points[j].x)
				{
					slope = std::numeric_limits<double>::infinity(); //防止重复元素没有斜率
					if (points[i].y == points[j].y)
					{
						samePointNum++;
						continue;
					}
				}
				else
				{
					slope = 1.0*(points[i].y - points[j].y) / (points[i].x - points[j].x);
				}

				int count = 0;
				if (slope_count.find(slope) != slope_count.end())
					count = ++slope_count[slope];
				else
				{
					count = 2;
					slope_count[slope] = 2;
				}
				if (point_max<count)
					point_max = count;
			}
			result = max(result, point_max + samePointNum);
		}
		return result;
	}
};


class Solution1 {
public:
	int maxPoints(vector<Point>& points)
	{
		if (points.size() <= 2) return points.size();
		int res = 0;
		for (int i = 0; i < points.size() - 1; i++) {
			int numVertical = 1, local = 1, duplicate = 0;
			unordered_map<double, int> map;
			for (int j = i + 1; j < points.size(); j++)
			if (points[i].x == points[j].x) // special cases
			if (points[i].y == points[j].y) // duplicate 
				duplicate++;
			else // vertical
				numVertical++;
			else {
				double slope = (points[i].y - points[j].y)*1.0 / (points[i].x - points[j].x);  //斜率有浮点精度的问题
				map[slope] == 0 ? map[slope] = 2 : map[slope]++;
				local = max(local, map[slope]);
			}
			local = max(local + duplicate, numVertical + duplicate);
			res = max(res, local);
		}
		return res;
	}
};

class Solution2  //可能跟编译器有关吧，vs2013下输出3，但是在leetcode下通过了
{
public:
	int maxPoints(vector<Point>& points) { // O(n^2)
		int result = 0;
		for (int i = 0; i < points.size(); i++) {
			auto &p1 = points[i];
			unordered_map<long double, int> hashT;
			int verticals = 1, duplicates = 0, local = 1;
			for (int j = i + 1; j < points.size(); j++) {
				auto &p2 = points[j];
				if (p1.y == p2.y && p1.x == p2.x) duplicates++;
				else if (p1.x == p2.x) verticals++;
				else {
					auto slope = static_cast<long double>(p1.y - p2.y) / (p1.x - p2.x);
					hashT[slope] = hashT[slope] ? 1 + hashT[slope] : 2;
					local = max(local, hashT[slope]);
				}
				local = max(local, verticals);
			}
			result = max(result, local + duplicates);
		}
		return result;
	}

};


//
//Your input
//
//[[0, 0], [94911151, 94911150], [94911152, 94911151]]
//Your answer
//
//3
//Expected answer
//
//2
int main()
{

	Solution2 S;
	vector<Point> points;
	Point p1(0, 0), p2(94911151, 94911150), p3(94911152, 94911151);//[[0,0],[94911151, 94911150],[94911152, 94911151]] //[[0,0],[-1,-1],[2,2]]



	points.push_back(p1);
	points.push_back(p2);
	points.push_back(p3);

	int ret=S.maxPoints(points);

	cout << ret << endl;

	return 0;
}

```
- 测试用例:[(0,0),(-1,-1),(2,2)]；浮点精度通不过

## reference

- [Leetcode: Max Points on a Line](http://blog.csdn.net/doc_sgl/article/details/17103427)
