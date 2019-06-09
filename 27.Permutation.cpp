/**
 * 字符串的排列
 * nowcoder: https://www.nowcoder.com/practice/fe6b651b66ae47d7acce78ffdd9a96c7?tpId=13&tqId=11180&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
 * */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using std::string;
using std::vector;

#if 0
class Solution {
public:
    vector<string> Permutation(string str) {
        /**
         * 刚刚我们尝试了 <algorithm> 库里的 next_permutation 函数
         * TODO 自己模拟实现一个 next_permutation 函数
         */
    }
};
#endif 

#if 1

class Solution {
public:
    vector<string> Permutation(string str) {
        /**
         * 听说 c++ >algorithm> 库里有一个 next_permutation 函数
         * 要不我们试试，哈哈哈
         */
        std::vector<std::string> ret;
        
        // 参数检验 如果 str 为空 就返回一个空的 vector
        if (str.empty())
        {
            return ret;
        }
       
        // std::string temp;
        std::sort(str.begin(), str.end());
        do 
        {
            ret.push_back(str);
        } while ( std::next_permutation(str.begin(), str.end()));
        
        
        return ret;
    }
};

#endif
