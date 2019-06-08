/**
 * 二叉搜索数的后序遍历序列
 * nowcoder: https://www.nowcoder.com/practice/a861533d45854474ac791d90e447bafd?tpId=13&tqId=11176&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
 * */

#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    bool VerifySquenceOfBST(vector<int>& sequence) {
        
        // 要说一颗空树是搜索二叉，好像也没毛病哦
        // 但是nowcoder不一样，空树不算搜索二叉
        // 如果这里返回 true  测试用例只能通过 87.50%
        if (sequence.empty())
        {
            return false;
        }
        
        return assist(sequence, 0, static_cast<int>(sequence.size()));
    }
private:
    bool assist(std::vector<int>& array, int left, int right);
};

bool Solution::assist(std::vector<int>& array, int left, int right)
{
    // 递归出口 区间只有一个元素 或者 区间内没有元素
    if (left+1 == right || left >= right)
    {
        return true;
    }
    
    // 之后就要考虑怎么划分区间来递归了
    /**
     * 对搜索二叉的后续遍历来说，序列最右侧的元素肯定是这颗搜索二叉的根节点
     * 我们从左到右遍历序列，第一个比最右侧元素大的元素，必定是当前根节点右子树的根节点
     * 以此来将序列划分为两个部分
     * 之后再判断这两个部分是否满足搜索二叉的性质
     * 根节点将序列分为两个部分 左子树的所有元素都小于根节点 右子树的所有元素都大于根节点
     */
    int pos = left;
    // 从左往右找第一个比 最右边元素 大的元素
    for (pos = left; pos < right-1; ++pos)
    {
        if (array[pos] > array[right-1])
        { // 找到位置
            break;
        }
    }
    
    // // 如果这个条件成立，搜索二叉已退化为左单只树
    // // 这并不能判断这是左单只，只能说明 初步判断左子树序列没有问题
    // // 至于是不是有问题，需要进一步判断，比如 4 2 1 3 
    // if (pos == right)
    // {
    //     return true;
    // }

   
    // 判断右子树
    for (int i = pos; i < right-1; ++i)
    {
        if (array[i] <= array[right-1])
        {
            return false;
        }
    }
    
    // 之后进行递归
    return assist(array, left, pos) && assist(array, pos, right-1);
}
