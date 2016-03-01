
//题目描述
//
//如何得到一个数据流中的中位数？如果从数据流中读出奇数个数值，那么中位数就是所有数值排序之后位于中间的数值。
//如果从数据流中读出偶数个数值，那么中位数就是所有数值排序之后中间两个数的平均值。

/**
对于数据流，对应的就是在线算法了，一道很经典的题目就是在1亿个数中找到最大的前100个数，
这是一道堆应用题，找最大的前100个数，那么我们就创建一个大小为100的最小化堆，每来一个元素就与堆顶元素比较，
因为堆顶元素是目前前100大数中的最小数，前来的元素如果比该元素大，那么就把原来的堆顶替换掉。
那么对于这一道题呢？如果单纯的把所有元素放到一个数组里，每次查找中位数最快也要O(n)，综合下来是O(n^2)的复杂度。
我们可以利用上面例子中的想法，用一个最大堆来维护当前前n/2小的元素，那么每次找中位数只到取出堆顶就可以了。
但是，有一个问题，数据要动态增长，有可能之前被替换掉的元素随着元素的增加又跑回来了，
所以我们不能单纯得向上题一样把元素丢掉，我们可以再用一个最小化堆来存前n/2大的元素。
*/

#include<vector>
#include <iostream>     // std::cout
#include <functional>   // std::greater
#include <algorithm>    // std::push_heap
using namespace std;

class Solution {
private:
	vector<int> min; //数组中的后一半元素组成一个最小化堆
	vector<int> max; //数组中的前一半元素组成一个最大化堆
public:
	void Insert(int num) {
		if (((min.size() + max.size()) & 1) == 0) {  //偶数数据的情况下，则在最小堆中插入元素
			if (max.size() > 0 && num < max[0]) {
				max.push_back(num);
				push_heap(max.begin(), max.end(), less<int>());
				num = max[0];
				pop_heap(max.begin(), max.end(), less<int>());
				max.pop_back();
			}
			min.push_back(num); //把前一半找到的最大值放到后一半中
			push_heap(min.begin(), min.end(), greater<int>());
		}
		else {
			if (min.size() > 0 && num > min[0]) {   //奇数数据的情况下，则在最大堆中插入元素
				min.push_back(num);
				push_heap(min.begin(), min.end(), greater<int>());
				num = min[0];
				pop_heap(min.begin(), min.end(), greater<int>());
				min.pop_back();
			}
			max.push_back(num); //把后一半找到的最大值放到前一半中
			push_heap(max.begin(), max.end(), less<int>());
		}
	}

	double GetMedian() {
		int size = min.size() + max.size();
		if (size == 0) return -1;
		double median = 0;
		if ((size & 1) != 0) {
			median = (double)min[0];
		}
		else {
			median = (double)(max[0] + min[0]) / 2;
		}
		return median;
	}
};

int main() {
	Solution s;
	vector<int> v{ 5, 2, 3, 4, 1, 6, 7, 0, 8 };
	for (int i = 0; i < v.size(); ++i) {
		s.Insert(v[i]);
		cout << s.GetMedian() << endl;
	}
	return 0;
}

//参考博客：http://www.cnblogs.com/easonliu/p/4441916.html