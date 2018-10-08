/*
 * 福尔摩斯的约会 (20)
 * 时间限制 1000 ms 内存限制 32768 KB 代码长度限制 100 KB 判断程序 Standard (来自 小小)
 * 题目描述
 * 大侦探福尔摩斯接到一张奇怪的字条：“我们约会吧！ 3485djDkxh4hhGE 2984akDfkkkkggEdsb s&hgsfdk d&Hyscvnm”。大侦探很
 *
 *  快就明白了，字条上奇怪的乱码实际上就是约会的时间“星期四 14:04”，因为前面两字符串中第1对相同的大写英文字母（大小写有区分）是
 *
 *   第4个字母'D'，代表星期四；第2对相同的字符是'E'，那是第5个英文字母，代表一天里的第14个钟头（于是一天的0点到23点由数字0到9、
 *
 *    以及大写字母A到N表示）；后面两字符串第1对相同的英文字母's'出现在第4个位置（从0开始计数）上，代表第4分钟。现给定两对字符串，
 *
 *     请帮助福尔摩斯解码得到约会的时间。
 *
 *     输入描述:
 *     输入在4行中分别给出4个非空、不包含空格、且长度不超过60的字符串。
 *
 *
 *     输出描述:
 *     在一行中输出约会的时间，格式为“DAY HH:MM”，其中“DAY”是某星期的3字符缩写，即MON表示星期一，TUE表示星期二，WED表示星期三，THU表示星期
 *     四，FRI表示星期五，SAT表示星期六，SUN表示星期日。题目输入保证每个测试存在唯一解。
 *
 *     输入例子:
 *     3485djDkxh4hhGE
 *     2984akDfkkkkggEdsb
 *     s&hgsfdk
 *     d&Hyscvnm
 *
 *     输出例子:
 *     THU 14:04
 * */

#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;

int main(void)
{
    char str1[60] = "";
    char str2[60] = "";
    char str3[60] = "";
    char str4[60] = "";

    std::cin >> str1;
    std::cin >> str2;
    std::cin >> str3;
    std::cin >> str4;

    int day = 0;
    int hour = 0;
    int minute = 0;

    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int len3 = strlen(str3);
    int len4 = strlen(str4);

    bool flag1 = true;
    bool flag2 = true;
    int len = len1 > len2 ? len2 : len1;
    for(int j = 0; j < len; ++j)
    {
        if(str1[j] == str2[j])
        {
            if(str1[j] >= 'A' && str1[j] <= 'G' && flag1)
            {
                day = str1[j] - 'A' + 1;
                flag1 = false;
                continue;
            }
            if(flag1 == false && (str1[j] >= 'A' && str1[j] <= 'N') && flag2)
            {
                hour = str1[j] - 'A' + 10;
                flag2 = false;
                break;
            }
            else if(flag1 == false && (str1[j] >= '0' && str1[j] <= '9') && flag2)
            {
                hour = str1[j] - '0';
                flag2 = false;
                break;
            }

        }
    }

    bool flag3 = true;
    len = len3 > len4 ? len4 : len3;
    for(int i = 0; i < len; ++i)
    {
        if(str3[i] == str4[i] && flag3 && ((str3[i] >= 'A' && str3[i] <= 'Z') || (str3[i] >= 'a' && str3[i] <= 'z')))
        {
            minute = i;
            flag3 = false;
            break;
        }
    }

    if(day == 1)
    {
        std::cout << "MON";
    }
    else if(day == 2)
    {
        std::cout << "TUE";
    }
    else if(day == 3)
    {
        std::cout << "WED";
    }
    else if(day == 4)
    {
        std::cout << "THU";
    }
    else if(day == 5)
    {
        std::cout << "FRI";
    }
    else if(day == 6)
    {
        std::cout << "SAT";
    }
    else if(day == 7)
    {
        std::cout << "SUN";
    }
    std::cout << ' ';
    std::cout << std::setw(2) << std::setfill('0') << hour;
    std::cout << ':';
    std::cout << std::setw(2) << std::setfill('0') << minute << std::endl;
    return 0;
}
