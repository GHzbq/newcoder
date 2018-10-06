/*
 *数字分类 (20)
时间限制 1000 ms 内存限制 32768 KB 代码长度限制 100 KB 判断程序 Standard (来自 小小)
题目描述
给定一系列正整数，请按要求对数字进行分类，并输出以下5个数字：

A1 = 能被5整除的数字中所有偶数的和；
A2 = 将被5除后余1的数字按给出顺序进行交错求和，即计算n1-n2+n3-n4...；
A3 = 被5除后余2的数字的个数；
A4 = 被5除后余3的数字的平均数，精确到小数点后1位；
A5 = 被5除后余4的数字中最大数字。

输入描述:
每个输入包含1个测试用例。每个测试用例先给出一个不超过1000的正整数N，随后给出N个不超过1000的待分类的正整数。数字间以空格分隔。


输出描述:
对给定的N个正整数，按题目要求计算A1~A5并在一行中顺序输出。数字间以空格分隔，但行末不得有多余空格。
若其中某一类数字不存在，则在相应位置输出“N”。

输入例子:
13 1 2 3 4 5 6 7 8 9 10 20 16 18

输出例子:
30 11 2 9.7 9
 * */

//#include <iostream>
//#include <stdio.h>
//
//#define N 1000
//int array[N];
//
//int main(void)
//{
//    int A1 = 0;
//    bool A1_flag = false;
//
//    int A2 = 0; 
//    int A2_flag = 1;
//    bool A2_flag2 = false;
//
//    int A3 = 0;
//    bool A3_flag = false;
//
//    float A4 = 0.0;
//    int A4_count = 0;
//    bool A4_flag = false;
//
//    int A5 = 0;
//    int A5_flag = 0;
//    bool A5_flag2 = false;
//
//    int n = 0;
//    int i = 0;
//    std::cin>>n;
//    while(i < n)
//    {
//        std::cin>>array[i];
//        ++i;
//    }
//
//    i = 0;
//    while(i < n)
//    {
//        if(array[i] % 10 == 0)
//        {
//            A1 += array[i];
//            A1_flag = true;
//            ++i;
//        }
//        else if(array[i] % 5 == 1)
//        {
//            A2 += A2_flag * array[i];
//            A2_flag2 = true;
//            A2_flag = -A2_flag;
//            ++i;
//        }
//        else if(array[i] % 5 == 2)
//        {
//            ++A3;
//            A3_flag = true;
//            ++i;
//        }
//        else if(array[i] % 5 == 3)
//        {
//            A4 += array[i];
//            A4_flag = true;
//            ++A4_count;
//        }
//        else if(array[i] % 5 == 4)
//        {
//            if(A5_flag == 0)
//            {
//                A5 = array[i];
//            }
//            else
//            {
//                A5 = A5 > array[i] ? A5 : array[i];
//            }
//            A5_flag2 = true;
//            ++i;
//        }
//        else 
//            ++i;
//    }
//
//    if(A1_flag == true)
//    {
//        printf("%d ", A1);
//    }
//    else
//    {
//        printf("N ");
//    }
//
//    if(A2_flag2 == true)
//    {
//        printf("%d ", A2);
//    }
//    else
//    {
//        printf("N ");
//    }
//
//    if(A3_flag == true)
//    {
//        printf("%d ", A3);
//    }
//    else
//    {
//        printf("N ");
//    }
//
//    if(A4_flag == true)
//    {
//        printf("%.1f ", A4 / A4_count);
//    }
//    else
//    {
//        printf("N ");
//    }
//
//    if(A5_flag2 == true)
//    {
//        printf("%d", A5);
//    }
//    else
//    {
//        printf("N");
//    }
//
//    printf("\n");
//
//    return 0;
//}

#include <iostream>
#include <stdio.h>

#define N 1000
int array[N];

int main(void)
{
    int A1 = 0;
    bool A1_flag = false;

    int A2 = 0; 
    int A2_flag = 1;
    bool A2_flag2 = false;

    int A3 = 0;
    bool A3_flag = false;

    float A4 = 0.0;
    int A4_count = 0;
    bool A4_flag = false;

    int A5 = 0;
    int A5_flag = 0;
    bool A5_flag2 = false;

    int i = 0;
    int n = 0;
    std::cin >> n;
    while(i < n)
    {
        std::cin >> array[i];
        int res = array[i] % 5;
        switch(res)
        {
        case 0:
            {
                if(array[i] % 2 == 0)
                {
                    A1 += array[i];
                    A1_flag = true;
                }
                break;
            }
        case 1:
            {
                A2 += A2_flag * array[i];
                A2_flag2 = true;
                A2_flag = -A2_flag;
                break;
            }
        case 2:
            {
                ++A3;
                A3_flag = true;
                break;
            }
        case 3:
            {
                A4 += array[i];
                A4_flag = true;
                ++A4_count;
                break;
            }
        case 4:
            {
                if(A5_flag == 0)
                {
                    A5 = array[i];
                    A5_flag = 1;
                }
                else 
                {
                    A5 = A5 > array[i] ? A5 : array[i];
                }
                A5_flag2 = true;
                break;
            }
        default: break;
        } // switch 
        ++i;
    }// while

    if(A1_flag == true)
    {
        printf("%d ", A1);
    }
    else
    {
        printf("N ");
    }

    if(A2_flag2 == true)
    {
        printf("%d ", A2);
    }
    else
    {
        printf("N ");
    }

    if(A3_flag == true)
    {
        printf("%d ", A3);
    }
    else
    {
        printf("N ");
    }

    if(A4_flag == true)
    {
        printf("%.1f ", A4 / A4_count);
    }
    else
    {
        printf("N ");
    }

    if(A5_flag2 == true)
    {
        printf("%d", A5);
    }
    else
    {
        printf("N");
    }

    printf("\n");
    return 0;
}// main


