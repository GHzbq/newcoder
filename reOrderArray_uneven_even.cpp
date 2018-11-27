/*
 * 输入一个整数数组，实现一个函数来调整该数组中数字的顺序，
 * 使得所有的奇数位于数组的前半部分，所有的偶数位于数组的后半部分，
 * 并保证奇数和奇数，偶数和偶数之间的相对位置不变。
 *
 * */

#include <iostream>
#include <vector>

// 这种方法虽然可以实现技术在前偶数在后，但是
// 这种方法没有达到题目的另一个要求
// 奇数和奇数，偶数和偶数的相对位置不变
/*
class Solution {
public:
    void reOrderArray(std::vector<int> &array) {
        int begin = 0;
        int end = (int)array.size() - 1;
        while(begin < end)
        {
            while(begin < end && array[begin] % 2 == 1)
            {
                ++begin;
            }

            while(begin < end && array[end] % 2 == 0)
            {
                --end;
            }

            if(begin < end)
            {
                int temp = array[begin];
                array[begin] = array[end];
                array[end] = temp;
            }
        }
    }
};*/

// 为什么上次的方法没有成功呢
// begin 从前面找一个偶数，end 从后面找一个奇数，
// 可能会打乱奇数与奇数之间的顺序
// 所以我们得换种解法
// 这次我们考虑从前往后遍历 ---- 前后指针法
class Solution {
public:
    void reOrderArray(std::vector<int> &array) {
        int ev = 0;
        int un = 0;
        int size = (int)array.size() - 1;
        while(ev != size && un != size)
        {
            while(ev != size && array[ev] % 2 == 1)
            {
                ++ev;
            }
            while(un != size && array[un] % 2 == 0)
            {
                ++un;
            }

            if(ev != size && un != size)
            {
                int temp = array[un];
                array[un] = array[ev];
                array[ev] = temp;
            }
        }
    }

};
