
## 题目

```
50. 数组剔除元素后的乘积

给定一个整数数组A。

定义B[i] = A[0] * ... * A[i-1] * A[i+1] * ... * A[n-1]， 计算B的时候请不要使用除法。
样例

给出A=[1, 2, 3]，返回 B为[6, 3, 2]

```

## 解析

```C++
class Solution {
public:
    /*
     * @param nums: Given an integers array A
     * @return: A long long array B and B[i]= A[0] * ... * A[i-1] * A[i+1] * ... * A[n-1]
     */
    vector<long long> productExcludeItself(vector<int> &nums) {
        // write your code here
        vector<long long> ret(nums.size(),1);
        for(int i=1;i<nums.size();i++)
        {
            ret[i]=ret[i-1]*nums[i-1];
        }
        long long right=nums[nums.size()-1]; //int 溢出
        for(int i=nums.size()-2;i>=0;i--)
        {
            ret[i]=ret[i]*right;
            right=right*nums[i];
        }
        return ret;
    }
};
```
