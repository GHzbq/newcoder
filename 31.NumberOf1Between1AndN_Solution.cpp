/**
 * 整数中1出现的次数
 * nowcoder: https://www.nowcoder.com/practice/bd7f978302044eee894445e244c7eee6?tpId=13&tqId=11184&rp=2&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking&tPage=2
 * */

#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    int NumberOf1Between1AndN_Solution(int n)
    {
        /** 
         * 当我们做不出来题的时候，不妨举几个例子，来分析一下题目
         * 1 2 3 4 5 6 7 8 9 观察发现 只有一个 1
         * 10 11 12 13 14 15 16 17 18 19 有 10 个 + 1 个 1
         * 20 21 22 23 24 25 26 27 28 29 有 1 个 1
         * ...
         * 90 91 92 93 94 95 96 97 98 99 有 1 个 1
         * 100 101 102 103 104 105 106 107 108 109 有 10 + 1 个1
         * 110 111 112 113 114 115 116 117 118 119 有 10 + 10 + 1 个 1
         * 
         */
        int number = 0;
        if (n <= 0)
        {
            return 0;
        }
        
        for (int i = 1; i <= n; ++i)
        {
            number += NumberOf1(i);
        }
        
        return number;
    }
 private:
    int NumberOf1(int n);
};

int Solution::NumberOf1(int n)
{
    int number = 0;
    while (n)
    {
        if (n % 10 == 1)
        {
            ++number;
        }
        
        n = n / 10;
    }
    
    return number;
}
