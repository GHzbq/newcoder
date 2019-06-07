/**
 * 包含 min 函数的栈
 * nowcoder: https://www.nowcoder.com/practice/4c776177d2c04c2494f2555c9fcc1e49?tpId=13&tqId=11173&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
 * */

#include <iostream>
#include <stack>

using std::stack;

class Solution {
public:
    /** 
     * 既然是实现一个包含min函数的栈，那 min 函数先不管，先得有个栈吧
     */
    void push(int value) {
        /**
         * 压栈操作，数据栈s直接进栈
         * 如果当前栈为空，对最小栈 ms 也直接压入元素
         * 如果 ms 不为空 取ms的栈顶元素比较，如果等于或者小于ms栈顶元素，入栈
         *                               否则不管
         */
        s.push(value);
        if (ms.empty())
        {
            ms.push(value);
        }
        else
        {
            int temp = ms.top();
            if (value <= temp)
            {
                ms.push(value);
            }
        }
    }
    void pop() {
        /**
         * 出栈操作：
         * 关于出栈pop操作，我们也判断一下数据栈s是否为空吧
         * 数据栈s直接出栈
         * 如果数据栈s的栈顶元素等于最小栈ms的栈顶元素，最小栈也pop栈顶元素
         */
        if (!s.empty())
        {
            if (s.top() == ms.top())
            {
                s.pop();
                ms.pop();
            }
            else
            {
                s.pop();
            }
        }
    }
    int top() {
        /**
         * 对返回栈顶元素的top操作，如果栈不空的话，取栈顶元素返回好了
         */
        if (!s.empty())
        {
            return s.top();
        }
        else
        {
            return 0;
        }
    }
    int min() {
        /**
         * 如果最小栈 ms 不为空的话，return ms.top()
         * 为空就返回0吧
         */
        if (!ms.empty())
        {
            return ms.top();
        }
        else
        {
            return 0;
        }
    }
private:
    std::stack<int> s;
    std::stack<int> ms;
};
