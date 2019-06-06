/*
 * 一只青蛙一次可以跳上1级台阶，也可以跳上2级。
 * 求该青蛙跳上一个n级的台阶总共有多少种跳法
 * （先后次序不同算不同的结果）。
 * https://www.nowcoder.com/practice/8c82a5b80378478f9484d87d1c5f12a4?tpId=13&tqId=11161&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
 * */

// 以下为 2019.06.06 更新 
class Solution {
public:
    int jumpFloor(int number) {
        /**
         * 首先明确青蛙的能力，他可以跳1级，可以跳两级
         * 好，接下来，我们来看看，青蛙怎么跳上5级台阶
         * 对5级台阶，它可以从4级台阶跳1步上来，
         *   也可以从3级台阶跳2步上来，我们不妨记为 f(5) = f(4) + f(3)
         * 对4级台阶，它可以从3级跳1步上来。也可以从2级跳1步上来 不妨记为 f(4) = f(3) + f(2)
         * 对3级台阶，它可以从2级台阶跳一步上来，也可以从1级台阶跳两步上来，f(3) = f(2) + f(1)
         * 对两级台阶，可以从1级跳1步上来，也可以直接调到2级，f(2) = 2;
         * f(1) = 1
         * 很完美的斐波那契数列
         */
        if (number <= 0)
        {
            return 0;
        }
        
        if(number == 1)
        {
            return 1;
        }
        
        if(number == 2)
        {
            return 2;
        }
        int f1 = 1;
        int f2 = 2;
        int f3 = 0;
        for(int i = 3; i <= number; ++i)
        {
            f3 = f1 + f2;
            f1 = f2;
            f2 = f3;
        }
        
        return f3;
    }
};
// 以上为 2019.06.06 更新

// class Solution {
// public:
//     int jumpFloor(int number) {
//         // 台阶数肯定不为负，就不考虑负数情况了
//         // 如果只有一个台阶 只有跳一步一种方法
//         // 如果有两个台阶，可以跳两次一步，也可以一次跳两步
//         // 就有两种方法
//         // 这两种情况很简单
//         // 我们先对这两种情况处理
//         int res[3] = {0, 1, 2};
//         if(number < 3)
//         {
//             return res[number];
//         }
// 
//         // 接下来我们考虑多个台阶的情况
//         /*假设现在6个台阶，
//          * 我们可以从第5跳一步到6，
//          * 这样的话有多少种方案跳到5就有多少种方案跳到6，
//          * 另外我们也可以从4跳两步跳到6，
//          * 跳到4有多少种方案的话，就有多少种方案跳到6*/
//         // 这就是一种转化的思想
//         int first = 1; 
//         int second = 2;
//         int third = 0;
//         for(int i = 3; i <= number; ++i)
//         {
//             third = first + second;
//             first = second;
//             second = third;
//         }
// 
//         return third;
//     }
// 
// };
