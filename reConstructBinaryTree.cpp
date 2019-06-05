#include <iostream>
#include <vector>

using namespace std;

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin);
    
private:
	TreeNode* bulid(std::vector<int>& pre, int preLeft, int preRight, std::vector<int>& in, int inLeft, int inRight);
};

TreeNode* Solution::reConstructBinaryTree(vector<int> pre, vector<int> vin) {
        /**
         * 我们回忆一下前序遍历的过程，
         * 对前序遍历来说，每次访问的必定是某颗子树的根节点，
         * 对中序遍历来说，它先访问这棵树的左子树，再访问根节点
         * 通过前序序列和中序序列。我们就可以确定哪些元素时左子树的元素，哪些元素是右子树的元素
         * 就比如样例：
         *    前序序列：1,2,4,7,3,5,6,8
         *    中序序列：4,7,2,1,5,3,8,6
         * 前序序列拿到 1 在看中序序列1左边的所有元素，必定是根节点为1的左子树
         * 然后递归去创建左子树就好了 全是递归的定义，然后递归创建右子树
         * 那么递归的出口是：中序没有元素了，就是递归的出口
         *           1
         *        2     3
         *     4      5   6
         *       7       8
         * 所以如果给定一个二叉树的前序遍历序列和中序遍历序列，完全是可以重建一棵二叉树的
         */
    if (pre.empty() || vin.empty() || pre.size() != vin.size())
	{
        // 条件都不满足，没办法创建二叉树
		return nullptr;
	}
        /**
         * 接下来我们考虑如何递归
         * 
         */
	TreeNode* root = bulid(pre, 0, static_cast<int>(pre.size()), vin, 0, static_cast<int>(vin.size()));
	return root;
}

TreeNode* Solution::bulid(std::vector<int>& pre, int preLeft, int preRight, std::vector<int>& in, int inLeft, int inRight)
{
	// std::cout << "preLeft = " << preLeft << "  preRight = " << preRight << "  inLeft = " << inLeft << "  inRight = " << inRight << std::endl;
	if (preLeft >= preRight)
	{
		return nullptr;
	}
	if (inLeft >= inRight)
	{
		return nullptr;
	}
	TreeNode* root = new TreeNode(pre[preLeft]);
    // 然后就要考虑 划分区间 进行递归
	int i = 0;
	for (i = inLeft; i < inRight; ++i)
	{
		if (in[i] == pre[preLeft])
		{
			break;
		}
	}
        // 我们用 i 记录了 pre[preLeft] 在 in 中出现的位置，
        // 那么从 [inLeft, i) 这个区间的元素 就是以pre[preLeft]为根节点的左子树上所有元素，递归创建左子树
	root->left = bulid(pre, preLeft + 1, preRight, in, inLeft, i);
	root->right = bulid(pre, preLeft + (i - inLeft) + 1, preRight, in, inLeft + (i - inLeft) + 1, inRight);
	return root;
}

// /**
//  ** Definition for binary tree
//  ** struct TreeNode {
//  **     int val;
//  **     TreeNode *left;
//  **     TreeNode *right;
//  **     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
//  ** };
//  *         */
// struct TreeNode
// {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode(int x)
//         :val(x)
//          ,left(NULL)
//          ,right(NULL)
//     {}
// };
// 
// 
// class Solution {
// public:
//     TreeNode* reConstructBinaryTree(std::vector<int> pre,std::vector<int> vin) {
//         if(pre.size() == 0 || vin.size() == 0)
//         {
//             return NULL;
//         }
//         
//         // 根节点肯定是前序遍历的第一个节点
//         TreeNode *root = new TreeNode(pre[0]);
//         // 然后找到根节点在中序遍历序列中的位置
//         size_t r = 0;
//         for(size_t i = 0; i < vin.size(); ++i)
//         {
//             if(vin[i] == pre[0])
//             {
//                 r = i;
//                 break;
//             }
//         }
//         // 中序遍历序列根节点以左是左子树，根节点往右是右子树
//         // 定义两个 vector 保存左右子树；
//         std::vector<int> left_in, left_pre;
//         std::vector<int> right_in, right_pre;
//         for(size_t i = 0; i < r; ++i)
//         {
//             left_in.push_back(vin[i]);
//             left_pre.push_back(pre[i+1]);
//         }
// 
//         for(size_t i = r+1; i < vin.size(); ++i)
//         {
//             right_in.push_back(vin[i]);
//             right_pre.push_back(pre[i]);
//         }
// 
//         // 之后递归创建左子树
//         root->left = reConstructBinaryTree(left_pre, left_in);
//         // 递归创建右子树
//         root->right = reConstructBinaryTree(right_pre, right_in);
// 
//         return root;
//     }
// 
// };
