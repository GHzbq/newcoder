/*
 * 1016. 部分A+B (15)
 * 时间限制 1000 ms 内存限制 32768 KB 代码长度限制 100 KB 判断程序 Standard (来自 小小)
 * 题目描述
 * 正整数A的“DA（为1位整数）部分”定义为由A中所有DA组成的新整数PA。例如：给定A = 3862767，DA = 6，则A的“6部分”PA是66，因为A中有2个6。
 *  
 *   现给定A、DA、B、DB，请编写程序计算PA + PB。
 *
 *   输入描述:
 *   输入在一行中依次给出A、DA、B、DB，中间以空格分隔，其中0 < A, B < 1010。
 *
 *
 *   输出描述:
 *   在一行中输出PA + PB的值。
 *
 *   输入例子:
 *   3862767 6 13530293 3
 *
 *   输出例子:
 *   399
 *
 * */

#include <iostream>
#include <stdio.h>


int main(void)
{
    int a = 0;
    int da = 0;
    int b = 0;
    int db = 0;

    std::cin >> a;
    std::cin >> da;
    std::cin >> b;
    std::cin >> db;
    int pa = 0;
    int pb = 0;
    int sum = 0;

    while(a > 0)
    {
        if(a % 10 == da)
        {
            pa = pa * 10 + da;
        }
        a = a / 10;
    }

    while(b > 0)
    {
        if(b % 10 == db)
        {
            pb = pb * 10 + db;
        }
        b = b / 10;
    }

    sum = pa + pb;
    
    std::cout << sum << std::endl;
    return 0;
}
