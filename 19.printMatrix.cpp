/**
 * 顺时针打印矩阵
 * nowcoder: https://www.nowcoder.com/practice/9b4c81a02cd34f76be2659fa0d54342a?tpId=13&tqId=11172&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
 * */
#include <iostream>
#include <vector>

using std::vector;


#if 1
class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
        /**
         * 其实感觉这道题很没有意思的
         * 可是尝试自己写的时候，却发现写不出来
         * 着实有一点眼高手低了
         * 那么再好好做一下吧，感觉这道题·考察的是边界条件的控制，跟算法和数据结构没有太大关系
         */
        std::vector<int> ret;
        // 如果数组为空，直接返回吧
        if(matrix.empty() || matrix[0].empty())
        {
            return ret;
        }
        
        int rows = static_cast<int>(matrix.size());
        int cols = static_cast<int>(matrix[0].size());
        int left = 0;
        int right = cols - 1;
        int up = 0;
        int down = rows-1;
        
        while(left <= right && up <= down)
        {
            // 从左往右打印一行
            for(int i = left; i <= right; ++i)
            {
                ret.push_back(matrix[up][i]);
            }
            
            // 从上往下打印一列
            if (up < down)
            {
                for (int i = up + 1; i <= down; ++i)
                {
                    ret.push_back(matrix[i][right]);
                }
            }
            
            // 从右往左打印一行
            if (up < down && left < right)
            {
                for (int i = right - 1; i >= left; --i)
                {
                    ret.push_back(matrix[down][i]);
                }
            }
            
            // 从下往上打印一列
            if (up + 1 < down && left < right)
            {
                for (int i = down -1; i > up; --i)
                {
                    ret.push_back(matrix[i][left]);
                }
            }
            
            ++left, --right, ++up, --down;
        }
        
        return ret;
    }
};

#endif


