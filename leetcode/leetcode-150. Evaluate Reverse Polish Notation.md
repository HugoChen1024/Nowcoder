## 题目描述

- Evaluate the value of an arithmetic expression in Reverse Polish Notation.

- Valid operators are +, -, *, /. Each operand may be an integer or another expression.

- Some examples:
```
  ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
  ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6
```
- Subscribe to see which companies asked this question.

## 思路分析

- 思路：由于逆波兰表达式本身不需要括号来限制哪个运算该先进行，因此可以直接利用栈来模拟计算：遇到操作数直接压栈，碰到操作符直接取栈顶的2个操作数进行计算（注意第一次取出来的是右操作数），然后再把计算结果压栈，如此循环下去。最后栈中剩下的唯一一个元素便是整个表达式的值
- 注意除法的除零保护

## AC代码：

```C++
class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        int ret=0;
        stack<int> s;  //将tokens往里面丢
        int L=0,R=0;  //左右操作树
        for(int i=0;i<tokens.size();i++)
            {
            if(tokens[i]=="+")
                {
                R=s.top(); //先是右操作数
                s.pop();
                L=s.top();
                s.pop();
                ret=L+R;
                s.push(ret);
            }else if(tokens[i]=="-")
                {
                R=s.top();
                s.pop();
                L=s.top();
                s.pop();
                ret=L-R;
                s.push(ret);
            }else if(tokens[i]=="*")
                {
                R=s.top();
                s.pop();
                L=s.top();
                s.pop();
                ret=L*R;
                s.push(ret);
            }else if(tokens[i]=="/")
                {
                R=s.top();
                s.pop();
                L=s.top();
                s.pop();
                if(R!=0)
                    ret=L/R;
                else
                    return -1;
                s.push(ret);
            }else
                {
                s.push(atoi(tokens[i].c_str()));
            }
        }//end for
         
        return s.top();
    }
};
```

## reference

- [表达式求值--堆栈应用](http://www.cnblogs.com/ranjiewen/p/6582019.html)

- [中缀表达式求值问题](http://www.cnblogs.com/dolphin0520/archive/2014/05/14/3708602.html)
