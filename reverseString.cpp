#include <iostream>
#include <algorithm>
#include <string>

void Reverse(std::string& str)
{
    if(str.empty())
    {
        return;
    }
    
    auto start = str.begin();
    auto end = str.begin();
    for(; end != str.end(); ++end)
    {
        if(*end == ' ' && start != end)
        {
            std::reverse(start, end);
            start = end + 1;
        }
    }
    // 对最后一个字符串 有点问题
    if(start != str.end())
    {
        std::reverse(start, end);
    }

    // 再对整个字符串翻转
    std::reverse(str.begin(), str.end());
}

int main(void)
{
    std::string str(100, '\0');
    while(std::getline(std::cin, str))
    {
        Reverse(str);
        std::cout << str << std::endl;
    }
}
