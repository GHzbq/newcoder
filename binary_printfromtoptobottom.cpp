#include <iostream>
#include <vector>
#include <queue>

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
    std::vector<int> PrintFromTopToBottom(TreeNode* root) {
        // 二叉树的层序遍历
        // 借助一个队列
		std::vector<int> res;
        std::queue<TreeNode*> ass;
        if(root == nullptr)
        {
            return res;
        }
        ass.push(root);
        while(!ass.empty())
        {
            TreeNode* tmp = ass.front();
            ass.pop();
            res.push_back(tmp->val);
            if(tmp->left != nullptr)
            {
                ass.push(tmp->left);
            }
            if(tmp->right != nullptr)
            {
                ass.push(tmp->right);
            }
        }
        

        return res;
    }

};
