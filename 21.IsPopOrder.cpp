/*
 * 栈的压入、弹出序列
 * nowcoder: https://www.nowcoder.com/practice/d77d11405cc7470d82554cb392585106?tpId=13&tqId=11174&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
 * 输入两个整数序列，第一个序列表示栈的压入顺序，
 * 请判断第二个序列是否可能为该栈的弹出顺序。
 * 假设压入栈的所有数字均不相等。
 * 例如序列1,2,3,4,5是某栈的压入顺序，
 * 序列4,5,3,2,1是该压栈序列对应的一个弹出序列，
 * 但4,3,5,1,2就不可能是该压栈序列的弹出序列。
 * （注意：这两个序列的长度是相等的）
 *
 * */



#include <iostream>
#include <vector>
#include <stack>

using std::vector;

#if 1
class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        /**
         * 借助一个栈吧
         */
        if (pushV.empty() || popV.empty() || pushV.size() != popV.size())
        {
            return false;
        }
        
        int size = static_cast<int>(pushV.size());
        int index = 0;
        std::stack<int> s;
        for (int i = 0; i < size; ++i)
        {
            // 如果栈为空，或者栈顶元素不为 popV[i] 的元素，就一直压栈
            // 如果 pushV 的所有元素都压入栈中了，就直接 return false
            while(s.empty() || s.top() != popV[i])
            {
                s.push(pushV[index]);
                ++index;
                if (index > size)
                {
                    return false;
                }
            }
            // 能走到这里，说明s.empty() == false 并且 s.top() == popV[i]
            // 直接出栈，比较后面的元素呗
            s.pop();
        }
        
        if (s.empty())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};
#endif

#if 0
class Solution {
public:
    bool IsPopOrder(std::vector<int> pushV,std::vector<int> popV) {
        /* 借用一个辅助的栈，遍历压栈顺序，
         * 先将第一个放入栈中，这里是1，
         * 然后判断栈顶元素是不是出栈顺序的第一个元素，
         * 这里是4，很显然1≠4，
         * 所以我们继续压栈，直到相等以后开始出栈，
         * 出栈一个元素，则将出栈顺序向后移动一位，直到不相等，
         * 这样循环等压栈顺序遍历完成，
         * 如果辅助栈还不为空，说明弹出序列不是该栈的弹出顺序。
         * */
        if(pushV.size() != popV.size())
        {
            return false;
        }
        std::stack<int> st;
        int index = 0;
        int size = (int)pushV.size();
        for(int i = 0; i < size; ++i)
        {
            while(st.empty() || st.top() != popV[i])
            {
                st.push(pushV[index++]);
                if(index > size)
                {
                    return false;
                }
            }

            st.pop();
        }

        if(!st.empty())
        {
            return false;
        }
        else
        {
            return true;
        }
    }

};
#endif

// class Solution {
// public:
//     bool IsPopOrder(std::vector<int> pushV,std::vector<int> popV) {
//         /* 借用一个辅助的栈，遍历压栈顺序，
//          * 先将第一个放入栈中，这里是1，
//          * 然后判断栈顶元素是不是出栈顺序的第一个元素，
//          * 这里是4，很显然1≠4，
//          * 所以我们继续压栈，直到相等以后开始出栈，
//          * 出栈一个元素，则将出栈顺序向后移动一位，直到不相等，
//          * 这样循环等压栈顺序遍历完成，
//          * 如果辅助栈还不为空，说明弹出序列不是该栈的弹出顺序。
//          * */
//         if(pushV.size() != popV.size())
//         {
//             return false;
//         }
//         std::stack<int> st;
//         int index = 0;
//         int size = (int)pushV.size();
//         for(int i = 0; i < size; ++i)
//         {
//             while(st.empty() || st.top() != popV[i])
//             {
//                 st.push(pushV[index++]);
//                 if(index > size)
//                 {
//                     return false;
//                 }
//             }
// 
//             st.pop();
//         }
// 
//         if(!st.empty())
//         {
//             return false;
//         }
//         else
//         {
//             return true;
//         }
//     }
// 
// };
