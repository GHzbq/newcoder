#include <iostream>
#include <vector>

class Solution {
public:
    bool Find(int target, std::vector<std::vector<int> > array) {
        for(size_t i = 0; i < array.size(); ++i)
        {
            for(size_t j = 0; j < array[i].size(); ++j)
            {
                if(array[i][j] == target)
                {
                    return true;
                }
            }
        }

        return false;
    }

};


bool Find(int target, std::vector<std::vector<int> > array) 
{
    // 先参数检验
    int rows = (int)array.size();
    if(rows == 0)
    {
        return false;
    }
    size_t cols = (int)array[0].size();
    if(cols == 0)
    {
        return false;
    }

    int row = 0;
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
