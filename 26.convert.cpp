/**
 * 二叉搜索树与双向链表
 * nowcoder: 
 * */

#include <iostream>
#include <vector>

/*
 * struct TreeNode {
 * 	int val;
 * 	struct TreeNode *left;
 * 	struct TreeNode *right;
 * 	TreeNode(int x) :
 * 			val(x), left(NULL), right(NULL) {
 * 	}
 * };
 **/
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
    TreeNode* Convert(TreeNode* pRoot)
    {
        /**
         * 这让我想到了二叉搜索树的序列化
         * 对一个节点来说，如果当前节点的左/右指针为空，就让为空的左指针指向这个节点的前驱
         * 让为空的右指针指向这个节点的后继
         * 搜索二叉的性质有一条是：将搜素二叉中序遍历，拿到一个有序的序列
         * 但是我们画一个图，就发现，序列化，并不能完全将一颗搜索二叉变为排序的双向链表，就比如
         *                         5
         *                   3           7
         *               2      4     6      9
         *           1                    8
         * 中序遍历肯定是一个有序的序列，但是 5 的左指针却是指向 3 的
         *                                    7 的右指针却是指向 9 的 这样就出现了问题
         * 或许我们把问题考虑复杂了，我直接中序遍历，然后保存每一个节点，之后修改每一个节点的指向不就好了嘛，或许我们可以试试这种写法
         */
        // 首先还是检查一下参数
        if (nullptr == pRoot)
        {
            return nullptr;
        }
        
        std::vector<TreeNode*> array;
        
        inOrder(pRoot, array);
        
        return assist(array);
    }
    
 private:
    void inOrder(TreeNode* root, std::vector<TreeNode*>& array);
    TreeNode* assist(std::vector<TreeNode*>& array);
};

void Solution::inOrder(TreeNode* root, std::vector<TreeNode*>& array)
{
    // 递归出口
    if (nullptr == root)
    {
        return;
    }
    
    inOrder(root->left, array);
    array.push_back(root);
    inOrder(root->right, array);
}

TreeNode* Solution::assist(std::vector<TreeNode*>& array)
{
    // 既然已经拿到中序序列了，修改指针的指向就可以了
    if (array.empty())
    {
        return nullptr;
    }
    
    // 对第一个节点，它的前驱（left）指向nullptr
    TreeNode* pPre = nullptr;
    TreeNode* pCur = array[0];
    TreeNode* pNext = nullptr;
    pCur->left = nullptr;
    if (array.size() != 1)
    {
        pCur->right = array[1];
    }
    else
    {
        pCur->right = nullptr;
    }
    
    int n = static_cast<int>(array.size());
    for (int i = 1; i < n; ++i)
    {
        pPre = array[i-1];
        pCur = array[i];
        if (i+1 == n)
        {
            pNext = nullptr;
        }
        else 
        {
            pNext = array[i+1];
        }
        
        pCur->left = pPre;
        pCur->right = pNext;
    }
    
    return array[0];
}
