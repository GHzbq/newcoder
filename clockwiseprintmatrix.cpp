/*
 * 输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字，
 * 例如，如果输入如下4 X 4矩阵： 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 
 * 则依次打印出数字1,2,3,4,8,12,16,15,14,13,9,5,6,7,11,10.
 *
 * */

#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<int> printMatrix(std::vector<std::vector<int> > matrix) {
        std::vector<int> res;
        int row ,col;
        if((row = (int)matrix.size()) == 0)
        {
            return res;
        }
        col = (int)matrix[0].size();
        int left = 0; // 左边界
        int right = col - 1; // 右边界
        int up = 0; // 上边界
        int down = row - 1; // 下边界

        while(left <= right && up <= down)
        {
            for(int i = left; i <= right; ++i)
            {
                res.push_back(matrix[i][up]);
            }
            if(up+1 <= down)
            {
                for(int j = up+1; j <= down; ++j)
                {
                    res.push_back(matrix[j][right]);
                }
            }
            if(left <= right - 1 && down-1 >= up)
            {
                for(int i = right - 1; i >= left; --i)
                {
                    res.push_back(matrix[down-1][i]);
                }
            }
            if(down-1 >= up+1 && left <= right-1)
            {
                for(int j = down - 1; j >= up+1; --j)
                {
                    res.push_back(matrix[j][left]);
                }
            }

            ++left, --right, ++up, --down;
        }

        return res;
    }
};
