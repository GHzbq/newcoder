/* 翻转字符串 */

#include <iostream>
#include <string>

class Solution
{
public:
    std::string reverseString(std::string s)
    {
        if(s.empty())
        {
            return s;
        }

        size_t begin = 0;
        size_t end = s.size() - 1;
        while(begin < end)
        {
            std::swap(s[begin], s[end]);
            ++begin;
            --end;
        }

        return s;
    }
    
};
