/*
 * 请实现一个函数，将一个字符串中的每个空格替换成“%20”。
 * 例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。
 *
 * */
//

// 2019.06.05 更新
#include <iostream>
#include <cstring>
class Solution {
public:
	void replaceSpace(char *str,int length) {
        (void)length;
        /**
         * 我们不妨先统计当前字符串中所有的空格，之后从后往前替换
         * 在不开辟新空间的情况下，如果从前往后替换，会覆盖掉原字符串中的字符
         */
        // 如果字符串为空，不需要处理
        if (!str)
        {
            return ;
        }
        int blankCount = 0;
        int oldStrLen = strlen(str);
        for ( int i = 0; i < oldStrLen; ++i)
        {
            if(str[i] == ' ')
            {
                ++blankCount;
            }
        }
        // 我们统计到了原字符串中所有的空格，那么替换之后字符串的长度应该为
        // 我们不妨先做个判断吧，万一源字符串中没有空格呢，我们就需要处理
        if (blankCount == 0)
        {
            return;
        }
        // 为什么新长度是 源字符串长度 + 2 * blankCount很好想
        // 我们是要替换空格，而空格本来就在原字符串中
        // int oldStrLen = strlen(str);
        int newStrLen = strlen(str) + 2 * blankCount;
        // 之后开始搬移元素以及替换
        // 这里我们假设题目给我们的空间足够容纳下替换后的字符串，不考虑越界的情况了
        // C语言是用数组模拟的字符串，并且一个C风格的字符串是以 '\0' 结尾
        // 所以直接把 str[newStrLen] = str[oldStrLen]没有任何问题
        while(oldStrLen >= 0)
        {
            if(str[oldStrLen] == ' ')
            {
                str[newStrLen--] = '0';
                str[newStrLen--] = '2';
                str[newStrLen--] = '%';
                --oldStrLen;
            }
            else
            {
                str[newStrLen--] = str[oldStrLen--];
            }
        }
	}
};
// #include <iostream>
// 
// class Solution {
// public:
// 	void replaceSpace(char *str,int length) {
//         (void)length;
//         int countOfBlank = 0;
//         int lenOfOriginalStr = 0;
//         char * p = str;
//         if(str == NULL)
//         {
//             return;
//         }
// 
//         while(*p)
//         {
//             ++lenOfOriginalStr;
//             if(*p++ == ' ')
//             {
//                 ++countOfBlank;
//             }
//         }
// 
//         int len_total = lenOfOriginalStr + 2 * countOfBlank;
//         char * str1 = str + len_total; // 指针偏移到 '\0'
//         char * str2 = str + lenOfOriginalStr; // 指针偏移到原始字符串最后
// 
//         while(str1 > str2)
//         {
//             if(*str2 == ' ')
//             {
//                 *str1-- = '0';
//                 *str1-- = '2';
//                 *str1 = '%';
//             }
//             else
//             {
//                 *str1 = *str2;
//             }
// 
//             --str1;
//             --str2;
//         }
// 	}
// };
