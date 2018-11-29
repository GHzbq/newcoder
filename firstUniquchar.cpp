/* 找出字符串中只出现一次的的字符 */

#include <iostream>
#include <string>

class Solution
{
public:
    int firstUniquchar(std::string s)
    {
        int count[256] = {0};
        for(auto it: s)
        {
            count[(int)it] += 1;
        }

        for(auto it : s)
        {
            if(1 == count[(int)it])
            {
                return (int)it;
            }
        }

        return -1;
    }
};



