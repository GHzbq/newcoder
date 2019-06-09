/**
 * 数组中出现次数超过一半的数字
 * nowcoder: https://www.nowcoder.com/practice/e8a1b01a2df14cb2b228b30ee6a92163?tpId=13&tqId=11181&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
 * */
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>

using std::vector;

class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        /**
         * 不如我们用 map 来统计每一个数字出现的次数吧
         */
        std::unordered_map<int, int> m;
        for (auto it : numbers)
        {
            ++m[it];
        }
        
        int n = static_cast<int>(numbers.size());
        n = n/2;
        
        for (auto it : m)
        {
            if (it.second > n)
            {
                return it.first;
            }
        }
        
        return 0;
    }
};

#if 0

class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
         /**
          * 我们用一种攻守阵地的思想吧
          *     从第一个元素开始，如果遇到的下一个元素，与本身相同，++count
          *                       如果不相同，就--count
          * 如果count == 0
          * 则这个人阵亡，换下一个人
          */
        // 先参数检验
        if (numbers.empty())
        {
            // 如果数组为空，没有元素自然不存在出现次数超过数组长度一半的元素 直接 return 0;
            return 0;
        }
    }
};

#endif 
