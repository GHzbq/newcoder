#include <iostream>

/*
 * 求 1 + 2 + 3 + ... + n
 * 要求不能使用乘除法、for、while、if、else、switch、case
 * 等关键词及条件判断语句（A?B:C）.
 *
 * */

class Solution
{
public:
    class Sum
    {
    public:
        Sum()
        {
            ++_count;
            _sum += _count;
        }

        static int GetSum()
        {
            return _sum;
        }

        static void Reset()
        {
            _count = 0;
            _sum = 0;
        }
    private:
        static int _count;
        static int _sum;
    };


    int Sum_Solution(int n)
    {
        Sum::Reset();
        Sum* ps = new Sum[n];
        delete[] ps;

        return Sum::GetSum();
    }
};

int Solution::Sum::_count = 0;
int Solution::Sum::_sum = 0;

int main()
{
    Solution s;
    std::cout << s.Sum_Solution(5) << std::endl;

    return 0;
}

