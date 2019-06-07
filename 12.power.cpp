/**
 * 数值的整数次方：
 * nowcoder: https://www.nowcoder.com/practice/1a834e5e3e1a4b7ba251417554e07c00?tpId=13&tqId=11165&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
 * */
#include <iostream>
#include <cmath>

class Solution {
public:
    double Power(double base, int exponent) {
        /**
         * 这道题的考点，我也不知道是什么
         * 难道是考察 pow 函数的使用？
         */
#if 0
        double res = pow(base, exponent);
        return res;
#endif
        /**
         * 或者考察我们的循环迭代？
         */
/* // 一段错误代码
        // 这样的提交只能通过 40.00%的测试用例，
        // 因为指数 exponent 可能是负数
        double res = base;
        for(int i = 1; i < exponent; ++i)
        {
            res = res * base;
        }
        
        return res;
*/
        /**
         * 我们来观察一下 3^-2 = 1/9 = 1 / 3^2
         */
        if (exponent == 0)
        {
            // 浮点数据与0比较 
            if ((base >= -0.000001) && (base <= 0.000001))
            {
                return 0;
            }
            else
            {
                return 1;
            }
        }
        
        bool negative = false;
        if (exponent < 0)
        {
            negative = true;
            exponent = -1 * exponent;
        }
        double res = base;
        for (int i = 1; i < exponent; ++i)
        {
            res *= base;
        }
        if(negative)
        {
            return 1 / res;
        }
        else 
        {
            return res;
        }
    }
};
