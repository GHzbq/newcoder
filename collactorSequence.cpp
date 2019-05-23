/**
 * 排序子序列
 * 来源：nowcoder
 * 连接：https://www.nowcoder.com/questionTerminal/2d3f6ddd82da445d804c95db22dcc471
 * 解题思路
 *     对一个序列来说非递增的含义就是 array[i] >= array[i+1]
 *     非递减的含义就是 array[i] <= array[i+1]
 *     这样会有三种情况
 *     array[i] < array[i+1]:   此时是递增的，只要一直循环，走完所有非递减(aray[i] <= array[i+1])，
 *                              直到条件不满足，就算是找到一个飞递减子序列了
 *     array[i] ==  array[i+1]: 对这种情况，直接 ++i 就可以了，因为你也不知道 array[i+1]与array[i+2]的大小情况
 *                              直接放到后面考虑好了
 *     array[i] > array[i+1]:   这种情况和第一种情况很类似，一样的处理办法
 *
 *     这样就统计出了有多少个 非递减子序列 和 非递增子序列
 * */
#include <iostream>
#include <vector>
#include <algorithm>

static const int N = 10*10*10*10*10;

int collatorSequence(std::vector<int> & array)
{
    if (array.empty() || array.size() == 1)
    {
        return 0;
    }
    
    if (array.size() == 2)
    {
        return 1;
    }
    
    int n = static_cast<int>(array.size()) - 1;
    int i = 0;
    int counter = 0;
    while(i < n)
    {
        if(array[i] < array[i+1])
        {
            while(i < n && array[i] <= array[i+1])
            {
                ++i;
            }
            ++counter;
            ++i;
        }
        else if(array[i] == array[i+1])
        {
            ++i;
        }
        else 
        {
            while(i < n && array[i] >= array[i+1])
            {
                ++i;
            }
            ++counter;
            ++i;
        }
    }
    
    return counter;
}

int main(void)
{
    // 对于 范围在 1 <= n <= 10^5 的 n 来说 用int存储足够了
    int n = 0;
    // 输入的元素 1 ≤ A_i ≤ 10^9 用 int 保存也足够了
    std::vector<int> array;
    int i = 0;
    int ret = 0;
    while((std::cin >> n) && ((n >= 1) && (n <= N)))
    {
        array.resize(n+1);
        // 读取用户输入
        for(i = 0; i < n; ++i)
        {
            std::cin >> array[i];
        }
        array[n] = 0;
        
        ret = collatorSequence(array);
        
        std::cout << ret << std::endl;
        array.clear();
    }
    
    return 0;
}
