/**
 * 最小的K个数
 * nowcoder: https://www.nowcoder.com/practice/6a296eb82cf844ca8539b57c23e6e9bf?tpId=13&tqId=11182&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
 * */

#include <iostream>
#include <vector>
#include <queue>

using std::vector;

class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        /**
         * 因为是找最小的k个数 假如输入超过 k 的话
         * 我们可以考虑建一个可以容纳k个元素的大堆，然后先插入k个元素
         * 之后在插入剩下的n-k个元素时，每次跟堆顶元素比较
         * 如果当前元素比堆顶元素要小，就将堆顶元素置换出来，
         * 如果比堆顶元素还大（或者等于），它就没有资格插入堆
         * 很好想：我建的是一个大堆，堆顶元素必然是最大的，如果比我目前最大的元素还要大，那肯定不是最小的k个数
         *         如果相等，没有必要插入
         *         只有小于的时候，才置换，然后调整堆里的元素，使其重新成为大堆
         * 当所有元素比较结束，堆里的元素，恰好就是我们要找的最小的k个数
         */
        std::vector<int> ret;
        int n = static_cast<int>(input.size());
        if (input.empty() || n < k || k <= 0)
        {
            return ret;
        }
        
        // 如果 数组中只有 k 个数 直接返回 不需要处理
        if (n == k)
        {
            ret = input;
            return ret;
        }
        
        // 之后我们要建一个大堆
        // C++ <queue> 头文件里包含了一个 priority_queue 我们叫做优先级队列
        // 其实就是堆，但是默认情况下，它是创建一个大堆，这就很方便了，不需要我们指定比较规则了
        std::priority_queue<int> heap(input.begin(), input.begin() + k);
        int top = heap.top();
        for (int i = k; i < n; ++i)
        {
            top = heap.top();
            if (input[i] < top)
            {
                heap.pop();
                heap.push(input[i]);
            }
        }
        
        ret.resize(k);
        for (int i = k-1; i >= 0; --i)
        {
            ret[i] = heap.top();
            heap.pop();
        }
        
        return ret;
    }
};
