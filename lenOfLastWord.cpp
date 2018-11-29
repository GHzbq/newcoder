/* 字符串中最后一个单词的长度 */

/* 不能用 cin 接收输入，而应该用 getline, 因为 cin 遇到空格就不读了 */

#include <iostream>
#include <string>

int main(void)
{
    std::string s1;
    while(getline(std::cin, s1))
    {
        size_t pos = s1.rfind(' ');
        std::cout << s1.size() - (pos + 1) << std::endl;
    }

    return 0;
}
