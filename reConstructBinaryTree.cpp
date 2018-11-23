#include <iostream>
#include <vector>

/**
 ** Definition for binary tree
 ** struct TreeNode {
 **     int val;
 **     TreeNode *left;
 **     TreeNode *right;
 **     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 ** };
 *         */
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x)
        :val(x)
         ,left(NULL)
         ,right(NULL)
    {}
};


class Solution {
public:
    TreeNode* reConstructBinaryTree(std::vector<int> pre,std::vector<int> vin) {
        if(pre.size() == 0 || vin.size() == 0)
        {
            return NULL;
        }
        
        // 根节点肯定是前序遍历的第一个节点
        TreeNode *root = new TreeNode(pre[0]);
        // 然后找到根节点在中序遍历序列中的位置
        size_t r = 0;
        for(size_t i = 0; i < vin.size(); ++i)
        {
            if(vin[i] == pre[0])
            {
                r = i;
                break;
            }
        }
        // 中序遍历序列根节点以左是左子树，根节点往右是右子树
        // 定义两个 vector 保存左右子树；
        std::vector<int> left_in, left_pre;
        std::vector<int> right_in, right_pre;
        for(size_t i = 0; i < r; ++i)
        {
            left_in.push_back(vin[i]);
            left_pre.push_back(pre[i+1]);
        }

        for(size_t i = r+1; i < vin.size(); ++i)
        {
            right_in.push_back(vin[i]);
            right_pre.push_back(pre[i]);
        }

        // 之后递归创建左子树
        root->left = reConstructBinaryTree(left_pre, left_in);
        // 递归创建右子树
        root->right = reConstructBinaryTree(right_pre, right_in);

        return root;
    }

};
