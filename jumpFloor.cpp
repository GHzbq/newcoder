/*
 *一只青蛙一次可以跳上1级台阶，也可以跳上2级。
 求该青蛙跳上一个n级的台阶总共有多少种跳法
 （先后次序不同算不同的结果）。
 * */

class Solution {
public:
    int jumpFloor(int number) {
        // 台阶数肯定不为负，就不考虑负数情况了
        // 如果只有一个台阶 只有跳一步一种方法
        // 如果有两个台阶，可以跳两次一步，也可以一次跳两步
        // 就有两种方法
        // 这两种情况很简单
        // 我们先对这两种情况处理
        int res[3] = {0, 1, 2};
        if(number < 3)
        {
            return res[number];
        }

        // 接下来我们考虑多个台阶的情况
        /*假设现在6个台阶，
         * 我们可以从第5跳一步到6，
         * 这样的话有多少种方案跳到5就有多少种方案跳到6，
         * 另外我们也可以从4跳两步跳到6，
         * 跳到4有多少种方案的话，就有多少种方案跳到6*/
        // 这就是一种转化的思想
        int first = 1; 
        int second = 2;
        int third = 0;
        for(int i = 3; i <= number; ++i)
        {
            third = first + second;
            first = second;
            second = third;
        }

        return third;
    }

};
