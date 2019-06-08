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


// 以下为 2019.06.08 更新
/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
using std::vector;
class Solution {
public:
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        /**
         * 二叉树的层序遍历
         * 借助队列实现吧
         */
        std::vector<int> ret;
        std::queue<TreeNode*>  q;
        
        // 如果是空树直接返回，不需要处理
        if (nullptr == root)
        {
            return ret;
        }
        
        // 将根节点入队列
        q.push(root);
        
        // 队列不为空，一直循环
        while (!q.empty())
        {
            root = q.front();
            q.pop();
            ret.push_back(root->val);
            if (root->left)
            {
                q.push(root->left);
            }
            if (root->right)
            {
                q.push(root->right);
            }
        }
        
        return ret;
    }
};
// 以上为 2019.06.08 更新

// class Solution {
// public:
//     std::vector<int> PrintFromTopToBottom(TreeNode* root) {
//         // 二叉树的层序遍历
//         // 借助一个队列
// 		std::vector<int> res;
//         std::queue<TreeNode*> ass;
//         if(root == nullptr)
//         {
//             return res;
//         }
//         ass.push(root);
//         while(!ass.empty())
//         {
//             TreeNode* tmp = ass.front();
//             ass.pop();
//             res.push_back(tmp->val);
//             if(tmp->left != nullptr)
//             {
//                 ass.push(tmp->left);
//             }
//             if(tmp->right != nullptr)
//             {
//                 ass.push(tmp->right);
//             }
//         }
//         
// 
//         return res;
//     }
// 
// };
