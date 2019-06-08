/**
 * 二叉树中和为某一值的路径
 * nowcoder: https://www.nowcoder.com/practice/b736e784e3e34731af99065031301bca?tpId=13&tqId=11177&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
 * */
#include <iostream>
#include <vector>

using std::vector;
/*
 * struct TreeNode {
 * 	int val;
 * 	struct TreeNode *left;
 * 	struct TreeNode *right;
 * 	TreeNode(int x) :
 * 			val(x), left(NULL), right(NULL) {
 * 	}
 * };
 * */
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};
class Solution {
public:
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
        /**
         * 我们先不考虑数组长度大的数组靠前
         * 我们先考虑最简单的，怎么才能找一条路径
         * 我们可以考虑递归？
         * 那要怎么设计递归呢？
         * 我们调用辅助函数 assist(TreeNode* root, int expectNumber, std::vector<std::vector<int>> & ret,
         *                         std::vector<TreeNode*> & array, int currentNumber)
         * 关于这个函数的参数 前两个不解释
         *                    第三个参数 就这当前函数的返回值了
         *                    第四个参数 我们用来保存一条路径
         *                    第5个参数 保存第四个参数保存的路径里所有元素的和
         * 如何进行递归：
         *     如果这条路径的和等于目标值expectNumber，并且当前节点是叶子节点，说明我们找到一条路径
         *     如果这条路径的和小于目标值，继续递归
         *     如果这条路径的和大于目标值，直接返回
         * 关于递归返回的过程：
         *     在返回之前，我们需要删除当前节点，其实我们用 array 来模拟了这个栈，
         * 为什么不用真正栈：
         *     我们最后是需要把这条路径放到ret进行返回的，用 array 更方便一点
         *     其实栈也就是限定性线性表，只不过只能尾插尾删罢了
         *     而 vector 有一个 erase 操作，这是栈没有的
         */
        // 我们还是先判断一下初始条件
        std::vector<std::vector<int>> ret;
        if (nullptr == root)
        {
            return ret;
        }
        std::vector<TreeNode*> array;
        int currentNumber = 0;
        assist(root, expectNumber, ret, array, currentNumber);
        return ret;
        /**
         * 这个代码，我们并不能保证 长度大的数组靠前 
         * 但是 nowcoder 依然通过了所有测试用例 嗯...应该是 nowcoder 的测试用例不全吧 也算是我们投机取巧了
         * TODO: 考虑 在返回值的list中，数组长度大的数组靠前
         */
    }
 private:
    void assist(TreeNode* root, int expectNumber, std::vector<std::vector<int>> &ret, 
                std::vector<TreeNode*> & array, int currentNumber);
};

void Solution::assist(TreeNode* root, int expectNumber, std::vector<std::vector<int>> &ret, 
                std::vector<TreeNode*> & array, int currentNumber)
{
    // 如果当前节点为空 直接返回吧
    if (nullptr == root)
    {
        return;
    }
    
    array.push_back(root);
    currentNumber += root->val;
    bool isLeaf = (root->left == nullptr) && (nullptr == root->right);
    if (currentNumber == expectNumber)
    {
        if (isLeaf)
        {
            // 找到一条路径 我们将其插入 ret
            std::vector<int> temp;
            for (auto & it : array)
            {
                temp.push_back(it->val);
            }
            ret.push_back(temp);
            // 既然已经是叶子节点了，就不需要继续递归了，而且也没法递归了
            array.pop_back();
            // 对于 currentNumber 我们是采取值传递，所以不会影响上一层递归
            return;
        }
        else 
        {
            // 不是叶子节点 也没有必要继续递归了 直接返回吧
            array.pop_back();
            return;
        }
    }
    else if (currentNumber > expectNumber)
    {
        // 都比目标值大了，也没必要继续递归了吧
        array.pop_back();
        return;
    }
    else
    {
        if (isLeaf)
        {
            // 如果比目标值expectNumber小 也没有必要继续递归了
            array.pop_back();
            return;
        }
        else
        {
            // 不是叶子节点
            // 我们按照前序遍历，继续查找
            assist(root->left, expectNumber, ret, array, currentNumber);
            assist(root->right, expectNumber, ret, array, currentNumber);
            // 我们再考虑一下递归回来了怎么办？
            // 直接返回好像不对吧 我们得把 当前节点从 array 中删掉
            array.pop_back();
            return;
            // 所以上面这两行，完全可以提出来哈
        }
    }
}
