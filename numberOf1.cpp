/*
 * 输入一个整数，输出该数二进制表示中1的个数。其中负数用补码表示。
 *
 * */

#include <iostream>

class Solution {
public:
     int  NumberOf1(int n) {
        int i = 0;
        int cnt = 0;
        int size = sizeof(int) * 8;
       
        while(i < size)
        {
            // 2      -->  0010
            // 1 << 1 -->  0010
            if(((1 << i) & n) != 0)
            {
                ++cnt;
            }
            ++i;
        }
        return cnt;
     }
};
