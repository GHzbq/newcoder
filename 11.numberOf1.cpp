/*
 * 输入一个整数，输出该数二进制表示中1的个数。其中负数用补码表示。
 *
 * */

#include <iostream>

class Solution {
public:
     int  NumberOf1(int n) {
         /**
          *　二进制中１的位数
          ×　将1左移i位，然后做 & 运算，判断结果是否为1
          * 是的话 ++count 不是的话 继续循环
          */
#if 0
         // 首先我们要拿到一个 int 在该平台下有多少bits 
         // 不管什么平台，一个字节8个bit总没错
         int num = sizeof(int) * 8;
         int count = 0;
         for(int i  = 0; i < num; ++i)
         {
             if ((1<<i) & n)
             {
                 ++count;
             }
         }
         
         return count;
#endif 
         /**
          * 经过我们的观察，我们发现，
          * 两个相邻的数，他们总是差1
          * 5: 0101
          * 4: 0100
          * &
          *    0100
          *    0011
          * &  
          *    0000
          * 经过两次&运算，num变为0，而count为2，刚好是5的二进制中1的位数
          */
         int count = 0;
         while(n)
         {
             ++count;
             n = n & (n-1);
         }
         return count;
     }
};

// class Solution {
// public:
//      int  NumberOf1(int n) {
//         int i = 0;
//         int cnt = 0;
//         int size = sizeof(int) * 8;
//        
//         while(i < size)
//         {
//             // 2      -->  0010
//             // 1 << 1 -->  0010
//             if(((1 << i) & n) != 0)
//             {
//                 ++cnt;
//             }
//             ++i;
//         }
//         return cnt;
//      }
// };
// 
// class Solution1 {
// public:
//      int  NumberOf1(int n) {
//          int count = 0;
//          while(n)
//          {
//              ++count;
//              n = n & (n - 1);
//          }
//          
//          return count;
//      }
// };
