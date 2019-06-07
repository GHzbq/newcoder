/**
 * 数的子结构
 * nowcoder:https://www.nowcoder.com/practice/6e196c44c7004d15b1610b9afca8bd88?tpId=13&tqId=11170&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
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
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2);
private:
    bool assist(TreeNode* pRoot1, TreeNode* pRoot2);
};

bool Solution::HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
{
    // 空树不是任意一个树的子结构
    if (!pRoot1 || !pRoot2)
    {
        return false;
    }
    
    return assist(pRoot1, pRoot2) || HasSubtree(pRoot1->left, pRoot2) || HasSubtree(pRoot1->right, pRoot2);
}

bool Solution::assist(TreeNode* pRoot1, TreeNode* pRoot2)
{
    if (!pRoot2)
    {
        return true;
    }
    
    if(!pRoot1)
    {
        return false;
    }
    
    if(pRoot1->val == pRoot2->val)
    {
        return assist(pRoot1->left, pRoot2->left) && assist(pRoot1->right, pRoot2->right);
    }
    else
    {
        return false;
    }
}
