/*
 *数素数 (20)
 时间限制 1000 ms 内存限制 32768 KB 代码长度限制 100 KB 判断程序 Standard (来自 小小)
 题目描述
 令Pi表示第i个素数。现任给两个正整数M <= N <= 10000，请输出PM到PN的所有素数。

 输入描述:
 输入在一行中给出M和N，其间以空格分隔。


 输出描述:
 输出从PM到PN的所有素数，每10个数字占1行，其间以空格分隔，但行末不得有多余空格。

 输入例子:
 5 27

 输出例子:
 11 13 17 19 23 29 31 37 41 43
 47 53 59 61 67 71 73 79 83 89
 97 101 103
 * */

#include <iostream>

int Is_Prime(int num)
{
    for(int i = 2; i * i <= num; ++i)
    {
        if(num % i == 0)
            return 0;
    }

    return 1;
}

int main(void)
{
    int M = 0;
    int N = 0;

    std::cin >> M >> N;
    int count = 0;
    int flag = 0;

    for (int i = 2; ; ++i)
    {
        if(Is_Prime(i))
        {
            ++count;
            if(count >= M && count <= N)
            {
                std::cout << i;
                ++flag;
                if(flag % 10 == 0)
                {
                    std::cout << std::endl;
                }
                else
                {
                    if(count + 1 > N)
                        break;
                    else
                        std::cout << ' ';
                }
            }
        }
    }//for

    std::cout << std::endl;

    return 0;
}
