/*
 * 一只青蛙一次可以跳上1级台阶，也可以跳上2级……它也可以跳上n级。
 * 求该青蛙跳上一个n级的台阶总共有多少种跳法。
 * https://www.nowcoder.com/practice/22243d016f6b47f2a6928b4313c85387?tpId=13&tqId=11162&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
 * */

// 以下为 2019.06.06 更新
class Solution {
public:
    int jumpFloorII(int number) {
        if(number <= 0)
        {
            return 0;
        }

        // 对一个n级台阶来说
        // 第一步有 n 种跳法
        // 跳一级，剩下 n-1 步的跳法为jumpFloorII(n-1) 
        // 跳两级，剩下 n-2 步的跳法为jumpFloorII(n-2)
        // 所以 jumpFloorII(n) = jumpFloorII(n-1)+jumpFloorII(n-2) + ...+ jumpFloorII(1)
        // 又有 jumpFloorII(n-1) = jumpFloorII(n-2) + ...+ jumpFloorII(1)
        // 所以 jumpFloorII(n) = 2 * f(n-1);
        // 若 n=1 jumpFloorII(1) = 1；
        // 若 n=2 jumpFloorII(2) = 2*jumpFloorII(1) = 2；
        // 若 n=3 jumpFloorII(3) = 2*jumpFloorII(2) = 4；
        // 
        // 若 n=n jumpFloorII(n) = 2^(n-1);
        int steps = 1;
        for(int i = 1; i < number; ++i)
        {
            steps *= 2;
        }
        
        return steps;
    }
};
// 以上为 2019.06.06 更新

// class Solution {
// public:
//     int jumpFloorII(int number) {
//         if(number <= 0)
//         {
//             return 0;
//         }
// 
//         // 对一个n级台阶来说
//         // 第一步有 n 种跳法
//         // 跳一级，剩下 n-1 步的跳法为jumpFloorII(n-1) 
//         // 跳两级，剩下 n-2 步的跳法为jumpFloorII(n-2)
//         // 所以 jumpFloorII(n) = jumpFloorII(n-1)+jumpFloorII(n-2) + ...+ jumpFloorII(1)
//         // 又有 jumpFloorII(n-1) = jumpFloorII(n-2) + ...+ jumpFloorII(1)
//         // 所以 jumpFloorII(n) = 2 * f(n-1);
//         // 若 n=1 jumpFloorII(1) = 1；
//         // 若 n=2 jumpFloorII(2) = 2*jumpFloorII(1) = 2；
//         // 若 n=3 jumpFloorII(3) = 2*jumpFloorII(2) = 4；
//         // 
//         // 若 n=n jumpFloorII(n) = 2^(n-1);
//         int steps = 1;
//         for(int i = 1; i < number; ++i)
//         {
//             steps *= 2;
//         }
//         
//         return steps;
//     }
// };
