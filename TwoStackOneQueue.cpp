// 用两个栈实现一个队列
#include <iostream>
#include <stack>

class Solution
{
public:
    void push(int node) {
        stack1.push(node);
    }

    int pop() {
        int val = 0;
        if(stack2.empty())
        {
            while(!stack1.empty())
            {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
        val = stack2.top();
        stack2.pop();
        return val;
    }

private:
    std::stack<int> stack1;
    std::stack<int> stack2;

};
