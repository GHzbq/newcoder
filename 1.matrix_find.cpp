#include <iostream>
#include <vector>

using namespace std;

// 2019.06.05 更新
class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        /**
         * 二维数组中的查找，直接暴力匹配。总能找到 target 
         */
#if 0
        if(array.empty())
        {
            return false;
        }
        int rows = static_cast<int>(array.size());
        int cols = static_cast<int>(array[0].size());
        for(int i = 0; i < rows; ++i)
        {
            cols = static_cast<int>(array[i].size());
            for(int j = 0; j < cols; ++j)
            {
                if (array[i][j] == target)
                {
                    return true;
                }
            }
        }
        
        return false;
#endif
        /*
         * 但是很明显这种方法的时间复杂度为O(n^2) 未免有点太高了
         * 再次观察题目，我们发现这个二维数组很有规律，
         * 从左往右递增，从上递增
         * 考虑到这样的规律，我们可以考虑优化本题
         * 我们选取当前数组最右上角的元素，然后比较，
         * 如果 array[row][col] > target，那么这一列的元素都可以排除掉，
         * 因为数组从上到下递增，下面的元素必定都比 array[row][col] 大，
         * 所以不可能在这一列找到 target, 我们 --col 这样就排除一列的搜索
         * 如果 array[row][col] < target,那么这一行的元素都可以被剔除，
         * 道理与上面一样
         */
        if (array.empty())
        {
            return false;
        }
        int rows = static_cast<int>(array.size());
        int cols = static_cast<int>(array[0].size());
        int row = 0; // 
        int col = cols - 1;
        while(row < rows && col >= 0)
        {
            if(array[row][col] == target)
            {
                return true;
            }
            else if(array[row][col] > target)
            {
                --col;
            }
            else
            {
                ++row;
            }
        }
        
        return false;
    }
};


// class Solution {
// public:
//     bool Find(int target, std::vector<std::vector<int> > array) {
//         for(size_t i = 0; i < array.size(); ++i)
//         {
//             for(size_t j = 0; j < array[i].size(); ++j)
//             {
//                 if(array[i][j] == target)
//                 {
//                     return true;
//                 }
//             }
//         }
// 
//         return false;
//     }
// 
// };
// 
// 
// bool Find(int target, std::vector<std::vector<int> > array) 
// {
//     // 先参数检验
//     int rows = (int)array.size();
//     if(rows == 0)
//     {
//         return false;
//     }
//     size_t cols = (int)array[0].size();
//     if(cols == 0)
//     {
//         return false;
//     }
// 
//     int row = 0;
//     int col = cols - 1;
//     while(row < rows && col >= 0)
//     {
//         if(array[row][col] == target)
//         {
//             return true;
//         }
//         else if(array[row][col] > target)
//         {
//             --col;
//         }
//         else
//         {
//             ++row;
//         }
//     }
// 
//     return false;
// }
