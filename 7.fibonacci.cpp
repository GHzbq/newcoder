/* 大家都知道斐波那契数列，现在要求输入一个整数n，请你输出斐波那契数列的第n项（从0开始，第0项为0）。
 * https://www.nowcoder.com/practice/c6c7742f5ba7442aada113136ddea0c3?tpId=13&tqId=11160&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
 * n<=39
 * */
//
class Solution {
public:
    int Fibonacci(int n) {
        // 既然是求斐波那契数列，一般两种思路吧，递归和循环迭代
        // 我们先考虑递归版本的
#if 0
        if (n <= 0)
        {
            return 0;
        }
        
        if (n == 1 || n == 2)
        {
            return 1;
        }
        
        return Fibonacci(n-1) + Fibonacci(n-2);
#endif 
        // 循环迭代版本
        if (n <= 0)
        {
            return 0;
        }
        
        if (n == 1 || n == 2)
        {
            return 1;
        }
        
        int first = 1;
        int second = 1;
        int third = 0;
        for(int i = 2; i < n; ++i)
        {
            third = first + second;
            first = second;
            second = third;
        }
        
        return third;
    }
};
//

// class Solution {
// public:
//     int Fibonacci(int n) {
//         if(n == 0)
//         {
//             return 0;
//         }
//         if(n == 1 || n == 2)
//         {
//             return 1;
//         }
// 
//         return Fibonacci(n-1)+Fibonacci(n-2);
//     }
// 
// };
