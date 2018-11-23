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
