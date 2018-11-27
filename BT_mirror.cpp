/*
 * 操作给定的二叉树，将其变换为源二叉树的镜像。
 * 二叉树的镜像定义：源二叉树 
    	    8
    	   /  \
    	  6   10
    	 / \  / \
    	5  7 9 11
    	镜像二叉树
    	    8
    	   /  \
    	  10   6
    	 / \  / \
    	11 9 7  5
 *
 * */

#include <iostream>
#include <stack>

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};

/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/

// 递归版本
class Solution1 {
public:
    void Mirror(TreeNode *pRoot) {
        if(pRoot == nullptr)
        {
            return ;
        }
        TreeNode * tmp = pRoot->left;
        pRoot->left = pRoot->right;
        pRoot->right = tmp;
        Mirror(pRoot->left);
        Mirror(pRoot->right);
    }
};

// 非递归版本
class Solution {
public:
    void Mirror(TreeNode *pRoot) 
    {

        if(pRoot == NULL)
            return;
        std::stack<TreeNode*> stackNode;

        stackNode.push(pRoot);
        while(stackNode.size())
        {
            TreeNode* tree = stackNode.top();
            stackNode.pop();
            if(tree->left != NULL || tree->right != NULL)
            {
                TreeNode *ptemp = tree->left;
                tree->left = tree->right;
                tree->right = ptemp;
            }
            if(tree->left)
                stackNode.push(tree->left);
            if(tree->right)
                stackNode.push(tree->right); 


        }

    }
};
