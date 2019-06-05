// 用两个栈实现一个队列
#include <iostream>
#include <stack>

using namespace std;

// 2019.6.5 更新
class Solution
{
public:
    void push(int node) {
        /**
         * 先考虑栈和队列的特性
         * 栈：  FILO 先进后出
         * 队列：FIFO 先进先出
         * 
         * push:入队列操作，我们不妨让所有的元素都入 stack1
         */
        stack1.push(node);
    }

    int pop() {
        /**
         * 队列的出队操作
         * 如果 stack2 非空，就出stack2 的 top, 然后 stack2.pop()
         * 如果 stack2 为空，就将 stack1 的全部元素倒过来，然后继续上面的操作
         */
        int temp = 0;
        // 需要先判断 stack2 是否为空
        // 不为空 直接出 stack2 的栈顶元素
        if (!stack2.empty())
        {
            temp = stack2.top();
            stack2.pop();
            return temp;
        }
        else
        {
            // 此时 stack2 为空
            // 将 stack1 的所有元素倒到 stack2
            while(!stack1.empty())
            {
                temp = stack1.top();
                stack1.pop();
                stack2.push(temp);
            }
            
            // 需要再次判断 stack2 是否非空
            if(!stack2.empty())
            {
                temp = stack2.top();
                stack2.pop();
                return temp;
            }
            else
            {// stack1 和 stack2 都为空 理论上应该返回 false 的，但是函数并没有这么设计 我们返回一个 0 为敬吧
                return 0;
            }
        }
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};

// class Solution
// {
// public:
//     void push(int node) {
//         stack1.push(node);
//     }
// 
//     int pop() {
//         int val = 0;
//         if(stack2.empty())
//         {
//             while(!stack1.empty())
//             {
//                 stack2.push(stack1.top());
//                 stack1.pop();
//             }
//         }
//         val = stack2.top();
//         stack2.pop();
//         return val;
//     }
// 
// private:
//     std::stack<int> stack1;
//     std::stack<int> stack2;
// 
// };

