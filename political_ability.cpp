/*
 * 德才论 (25)
 * 时间限制 1000 ms 内存限制 32768 KB 代码长度限制 100 KB 判断程序 Standard (来自 小小)
 * 题目描述
 * 宋代史学家司马光在《资治通鉴》中有一段著名的“德才论”：“是故才德全尽谓之圣人，才德兼亡谓之愚人，德胜才谓之君子，才胜德谓之
 * 小人。凡取人之术，苟不得圣人，君子而与之，与其得小人，不若得愚人。”
 *
 * 现给出一批考生的德才分数，请根据司马光的理论给出录取排名。
 *
 * 输入描述:
 * 输入第1行给出3个正整数，分别为：N（<=105），即考生总数；L（>=60），为录取最低分数线，即德分和才分均不低于L的考生才有资格
 * 被考虑录取；H（<100），为优先录取线——德分和才分均不低于此线的被定义为“才德全尽”，此类考生按德才总分从高到低排序；才分不到
 * 但德分到线的一类考生属于“德胜才”，也按总分排序，但排在第一类考生之后；德才分均低于H，但是德分不低于才分的考生属于“才德兼
 * 亡”但尚有“德胜才”者，按总分排序，但排在第二类考生之后；其他达到最低线L的考生也按总分排序，但排在第三类考生之后。
 *
 * 随后N行，每行给出一位考生的信息，包括：准考证号、德分、才分，其中准考证号为8位整数，德才分为区间[0, 100]内的整数。数字间以空格分隔。
 *
 *
 * 输出描述:
 * 输出第1行首先给出达到最低分数线的考生人数M，随后M行，每行按照输入格式输出一位考生的信息，考生按输入中说明的规则从高到低排序。当某类考生中有多人
 * 总分相同时，按其德分降序排列；若德分也并列，则按准考证号的升序输出。
 *
 * 输入例子:
 * 14 60 80
 * 10000001 64 90
 * 10000002 90 60
 * 10000011 85 80
 * 10000003 85 80
 * 10000004 80 85
 * 10000005 82 77
 * 10000006 83 76
 * 10000007 90 78
 * 10000008 75 79
 * 10000009 59 90
 * 10000010 88 45
 * 10000012 80 100
 * 10000013 90 99
 * 10000014 66 60
 *
 * 输出例子:
 * 12
 * 10000013 90 99
 * 10000012 80 100
 * 10000003 85 80
 * 10000011 85 80
 * 10000004 80 85
 * 10000007 90 78
 * 10000006 83 76
 * 10000005 82 77
 * 10000002 90 60
 * 10000014 66 60
 * 10000008 75 79
 * 10000001 64 90
 *
 * */

// #include <iostream>
// #include <algorithm>
// #include <vector>
// 
// struct Student 
// {
//     int number;
//     int political;
//     int ability;
//     
//     Student(int number = 0, int political = 0, int ability = 0):
//         number(number), political(political), ability(ability)
//     {}
// };
// 
// std::vector<Student> stu[4];
// int N, L, H;
// int n, a, p;
// 
// int select(int p, int a)
// {
//     if(p >= H && a >= H)
//     {
//         return 0;// 德才全尽
//     }
//     else if(p >= H && a >= L)
//     {
//         return 1;// 德胜才
//     }
//     else if(p >= L && a >= L && p >= a)
//     {
//         return 2; // 德才兼亡 但尚有 德胜才
//     }
//     else if(p >= L && a >= L && p < a)
//     {
//         return 3; // 合格
//     }
//     else 
//         return 4; // 不合格
// }
// 
// bool myobject(Student i, Student j)
// {
//     if((i.political + i.ability) != (j.political + j.ability))
//         return (i.political + i.ability) > (j.political + j.ability);
//     else if(i.political != j.political)
//         return i.political > j.political;
//     else
//         return i.number > j.number;
// }
// 
// int main(void)
// {
//     int M = 0;
//     int chose = 0;
//     std::cin >> N >> L >> H;
//     for(int i = 0; i < N; ++i)
//     {
//         std::cin >> n >> p >> a;
//         chose = select(p, a);
//         if(chose < 4)
//         {
//             ++M;
//             Student st(n, p, a);
//             stu[chose].push_back(st);
//         }
//     }
// 
//     for(int i = 0; i < 4; ++i)
//     {
//         sort(stu[i].begin(), stu[i].begin() + stu[i].size(), myobject);
//     }
// 
//     std::cout << M << std::endl;
//     for(int i = 0; i < 4; ++i)
//     {
//         for(unsigned long j = 0; j < stu[i].size(); ++j)
//         {
//             std::cout << stu[i][j].number << ' ' << stu[i][j].political << ' ' << stu[i][j].ability << std::endl;
//         }
//     }
// 
//     return 0;
// }

#include <iostream>
#include <cstdio>
#include <string>
#include <cctype>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn = 10005; 
struct stu{
    int num;
    int de;
    int cai;
    stu(int num=0,int de=0,int cai=0):num(num),de(de),cai(cai){}
};
vector<stu> st[4];
int h,l,n;
int num,d,c;
bool myf (stu i,stu j) {
    if((i.cai+i.de)!=(j.cai+j.de)) 
        return (i.cai+i.de)>(j.cai+j.de); 
    else if(i.de!=j.de)
        return i.de>j.de;
    else
        return i.num<j.num;
}//降序排列
int chose(int d,int c)
{
    if(d>=h&&c>=h)
        return 0;
    else if(d>=h&&c>=l)
        return 1;
    else if(d>=l&&c>=l&&d>=c)
        return 2;
    else if(d>=l&&c>=l&&d<c)
        return 3;
    else
        return 4;
}
int main() {
    cin>>n>>l>>h;
    int ch;
    int cnt = 0;
    for(int i = 0;i<n;i++)
    {
        cin>>num>>d>>c;
        ch = chose(d,c);
        if(ch<4)
        {
            cnt++;
            stu stua(num,d,c);
            st[ch].push_back(stua);
        }
              
    }
    for(int i = 0;i<4;i++)
    {
        sort(st[i].begin(),st[i].begin()+st[i].size(),myf);
    }
    cout<<cnt<<endl;
    for(int i = 0;i<4;i++)
    {
        for(int j = 0;j<st[i].size();j++)
        {
            cout<<st[i][j].num<<" "<<st[i][j].de<<" "<<st[i][j].cai<<endl;
        }
    }
    return 0;
}
