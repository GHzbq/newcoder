/**
 * 最大连续子数组的和
 * nowcoder: https://www.nowcoder.com/practice/459bd355da1549fa8a49e350bf3df484?tpId=13&tqId=11183&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
 * */

#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        /**
         * 动态规划：
         * 可以令 currentSum 是以当前元素结尾的最大连续子数组的和
         *        maxSum     是全局的最大子数组的和
         * 当往后扫描时，对第j个元素有两种选择，要么放到前面找到的子数组，要么作为新子数组的第一个元素：
         *     如果 currentSum>0, 则令 currentSum 加上 array[j]
         *     如果 currentSum<0, 则 currentSum 被置为当前元素，即 currentSum = a[j]
         * 如果设 currentSum(j) 为以j结尾的最大连续子数组的和
         * 那么 currentSum(j) = max{0, currentSum[j-1]+a[j]}
         * 如果 maxSum < currentSum,则更新maxSum = currentSum;
         * 否则 maxSum 保持原值，不更新
         */
        
        // 检验参数
        if (array.empty())
        {
            return 0;
        }
        
        int currentSum = 0;
        int maxSum = array[0]; // 如果数组全为负数的情况，返回最大数
        int n = static_cast<int>(array.size());
        
        for (int j = 0; j < n; ++j)
        {
            if (currentSum >= 0)
            {
                currentSum += array[j];
            }
            else 
            {
                currentSum = array[j];
            }
            
            if (currentSum > maxSum)
            {
                maxSum = currentSum;
            }
        }
        
        return maxSum;
    }
};
