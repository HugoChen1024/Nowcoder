## 题目

- Reverse digits of an integer.
```
Example1: x = 123, return 321
Example2: x = -123, return -321
```
## 思路分析：

```
Have you thought about this?
Here are some good questions to ask before coding. Bonus points for you if you have already thought through this!

If the integer's last digit is 0, what should the output be? ie, cases such as 10, 100.

Did you notice that the reversed integer might overflow? Assume the input is a 32-bit integer, then the reverse of 1000000003 overflows. How should you handle such cases?

For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.

Note:
The input is assumed to be a 32-bit signed integer. Your function should return 0 when the reversed integer overflows.

思路如下：
将每个字符存储，%取余 整除取出每一个数位的大小；
对于取出来的每个数位进行反向组合 12132 ->23121，这里特别说明使用long long存储；
如何判断越界问题：long long 存储数据与 INI_MAX INI_MIN边界对比，越界则返回0;
备注: limits.h 中有define INI_MAX 和 INI_MIN

```
## AC代码

```C++
class Solution {
public:
    int reverse(int x) {
    if (x < 10 && x > -10)
    {
        return x;
    }

    vector<int> vecNum(10, 0); // 十位数字存储即可
    int nIndex = 0;
    while (0 != x)
    {
        vecNum[nIndex++] = x % 10;
        x /= 10;
    }

    int nBgn = 0;
    long long nTemp = 0;
    while (nBgn < nIndex)
    {
        nTemp = nTemp * 10 + vecNum[nBgn];
        ++nBgn;
    }

    if (nTemp > INT_MAX || nTemp < INT_MIN)
    {
        return 0;
    }

    return nTemp;
}
};
```
## 题目来源

- [7. Reverse Integer](https://leetcode.com/problems/reverse-integer/#/description)
