/*
 * 输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。
 * 如果是则输出Yes,否则输出No。
 * 假设输入的数组的任意两个数字都互不相同。
 *
 * */

#include <iostream>
#include <vector>

class Solution {
public:
    bool VerifySquenceOfBST(std::vector<int> sequence) {
        // 二叉搜索树的后序序列的合法序列是，
        // 对于一个序列S，最后一个元素是x （也就是根），
        // 如果去掉最后一个元素的序列为T，那么T满足：
        // T可以分成两段，前一段（左子树）小于x，后一段（右子树）大于x，
        // 且这两段（子树）都是合法的后序序列。
        // 完美的递归定义
        if(sequence.size() == 0)
        {
            return false;
        }

        return judge(sequence, 0, sequence.size());
    }
private:
    bool judge(std::vector<int> &v, int left, int right)
    {
        // 如果区间内只有一个元素或者没有元素，直接返回 true
        if(left+1 >= right)
        {
            return true;
        }
        // 从左到右找到第一个大于最后一个元素的位置
        int last = v[right - 1];
        int i = left;
        for(i = left; i < right - 1; ++i)
        {
            if(v[i] > last)
            {
                break;
            }
        }
        for(int j = i; j < right; ++j)
        {
            if(v[j] < last)
            {
                return false;
            }
        }
        
        return judge(v, left, i) && judge(v, i, right - 1);
    }
};

/*
class Solution 
{
    bool judge(std::vector<int>& a, int l, int r)
    {
        if(l >= r) 
            return true;
        int i = r;
        while(i > l && a[i - 1] > a[r]) 
            --i;
        for(int j = i - 1; j >= l; --j) 
            if(a[j] > a[r]) 
                return false;

        return judge(a, l, i - 1) && (judge(a, i, r - 1));
    }
public:
    bool VerifySquenceOfBST(std::vector<int> a) 
    {
        if(!a.size()) 
            return false;

        return judge(a, 0, a.size() - 1);
    }
};*/ 
