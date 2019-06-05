/*
 * 输入一个链表，按链表值从尾到头的顺序返回一个ArrayList。
 * */

#include <iostream>
#include <vector>
#include <stack>

using namespace std;


// 2019.6.5 更新 

/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/

struct ListNode {
      int val;
      struct ListNode *next;
      ListNode(int x) :
            val(x), next(NULL) {
      }
};

class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        /**
         * 利用 vector 的 insert(vec.begin(), val)方法很简单的就可以完成这个函数
         */
#if 0
        std::vector<int> ret;
        if (!head)
        {
            return ret;
        }
        while(head != nullptr)
        {
            ret.insert(ret.begin(), head->val);
            head = head->next;
        }
        
        return ret;
#endif
        /**
         * 但是很明显，这个题不是考察我们 vector 的操作
         * 所以我们还是老实的用常规思路来解决这个问题
         * 既然要从尾到头打印链表，单链表的话，我们是没有办法从尾再往前走的
         * 所以我们可以考虑递归
         * 我们再定义一个辅助函数来完成这个递归操作吧
         */
#if 0
        std::vector<int> ret;
        assist(ret, head);
        return ret;
#endif
        /** 
         * 既然递归可以解决，我们借助于栈，应该也是可以完成这个功能的
         */
        std::stack<ListNode*> s;
        std::vector<int> ret;
        while(head)
        {
            s.push(head);
            head = head->next;
        }
        // 之后出栈，依次push_back到vector里即可
        while(!s.empty())
        {
            head = s.top();
            s.pop();
            ret.push_back(head->val);
        }
        return ret;
        
    }
private:
    void assist(std::vector<int>& array, ListNode* head)
    {
        // 这是递归出口
        if(head == nullptr)
        {
            return;
        }
        
        assist(array, head->next);
        array.push_back(head->val);
    }
};

// /**
//  * *  struct ListNode {
//  * *        int val;
//  * *        struct ListNode *next;
//  * *        ListNode(int x) :
//  * *              val(x), next(NULL) {
//  * *        }
//  * *  };
//  * */
// 
// 
// struct ListNode 
// {
//     int val;
//     struct ListNode *next;
//     ListNode(int x) 
//         :val(x)
//          , next(NULL) 
//     {}
// };
// 
// class Solution {
// public:
//     std::vector<int> printListFromTailToHead(ListNode* head)
//     {
//         std::vector<int> res;
//         while(head != nullptr)
//         {
//             res.insert(res.begin(), head->val);
//             head = head->next;
//         }
// 
//         return res;
//     }
// };
