/*
 * 输入一个整数数组，实现一个函数来调整该数组中数字的顺序，
 * 使得所有的奇数位于数组的前半部分，所有的偶数位于数组的后半部分，
 * 并保证奇数和奇数，偶数和偶数之间的相对位置不变。
 *
 * */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void reOrderArray(vector<int> &array) {
        /**
         * 说实话，拿到这道题，我的第一想法是用快排的思想
         * 可是转念一想，又不对
         * 2， 7， 8， 9， 3， 6， 5， 1， 4， 0
         *    ·！                           ！
         * 2， 0， 8， 9， 3， 6， 5， 1， 4， 7
         * 之后就不写了吧，很明显，偶数与偶数之间的相对位置已经改变
         * 2， 8， 6， 4， 0， 7， 9， 3， 5， 1 <- 这是理论上的值
         * 所以我们第一个办法呢，可以借助辅助空间嘛
         */
#if 1
        if (array.empty())
        {
            // 数组为空 直接返回吧
            return;
        }
        std::vector<int> temp(array.size());
        // 遍历一遍数组，统计奇数的个数
        int count = 0;
        for (auto it : array)
        {
            if (it % 2 == 1)
            {
                ++count;
            }
        }
        // 奇数开始存储的下标
        int en = 0;
        // 偶数开始存储的下标
        int old = 0 + count;
        for (auto it : array)
        {
            if (it % 2 == 1)
            {
                temp[en++] = it;
            }
            else
            {
                temp[old++] = it;
            }
        }
        
        std::swap(temp, array);
#endif 
        /**
         * 这样的话，时间复杂度为 O(n) 可是空间复杂度也是 O(n)
         * 面试的时候，面试官极有可能让你写出 时间为 O(n) 空间为O(1)的算法
         * 所以我们再考虑一下，有没有优化的策略
         * 我们再想想快排的实现吧，快排有很多版本，但是思想都是一样的，只是实现的方式不同
         * 最开始我们发现，一头一尾指针，没办法解决这个问题，那我们考虑一下以前一后指针是否可以实现
         * 
         * 经过尝试，也是不行的，它会改变奇偶相对顺序
         * 
         * 我没有想到 时间为 O(n) 空间为 O(1) 的解法
         */
    }
};

// // 这种方法虽然可以实现技术在前偶数在后，但是
// // 这种方法没有达到题目的另一个要求
// // 奇数和奇数，偶数和偶数的相对位置不变
// /*
// class Solution {
// public:
//     void reOrderArray(std::vector<int> &array) {
//         int begin = 0;
//         int end = (int)array.size() - 1;
//         while(begin < end)
//         {
//             while(begin < end && array[begin] % 2 == 1)
//             {
//                 ++begin;
//             }
// 
//             while(begin < end && array[end] % 2 == 0)
//             {
//                 --end;
//             }
// 
//             if(begin < end)
//             {
//                 int temp = array[begin];
//                 array[begin] = array[end];
//                 array[end] = temp;
//             }
//         }
//     }
// };*/
// 
// // 为什么上次的方法没有成功呢
// // begin 从前面找一个偶数，end 从后面找一个奇数，
// // 可能会打乱奇数与奇数之间的顺序
// // 所以我们得换种解法
// // 这次我们考虑从前往后遍历 ---- 前后指针法
// class Solution {
// public:
//     void reOrderArray(std::vector<int> &array) {
//         int ev = 0;
//         int un = 0;
//         int size = (int)array.size() - 1;
//         while(ev != size && un != size)
//         {
//             while(ev != size && array[ev] % 2 == 1)
//             {
//                 ++ev;
//             }
//             while(un != size && array[un] % 2 == 0)
//             {
//                 ++un;
//             }
// 
//             if(ev != size && un != size)
//             {
//                 int temp = array[un];
//                 array[un] = array[ev];
//                 array[ev] = temp;
//             }
//         }
//     }
// 
// };
