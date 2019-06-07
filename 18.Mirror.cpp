/**
 * 二叉树的镜像
 * nowcoder: https://www.nowcoder.com/practice/564f4c26aa584921bc75623e48ca3011?tpId=13&tqId=11171&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
 * */

#include <iostream>

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
    void Mirror(TreeNode *pRoot);
};

void Solution::Mirror(TreeNode* pRoot)
{
    if (!pRoot)
    {
        return;
    }
    
    std::swap(pRoot->left, pRoot->right);
    Mirror(pRoot->left);
    Mirror(pRoot->right);
}
