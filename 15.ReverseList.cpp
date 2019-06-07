/**
 * 反转链表
 * nowcoder:https://www.nowcoder.com/practice/75e878df47f24fdc9dc3e400ec6058ca?tpId=13&tqId=11168&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
 * */
#include <iostream>

/*
 * struct ListNode {
 * 	int val;
 * 	struct ListNode *next;
 * 	ListNode(int x) :
 * 			val(x), next(NULL) {
 * 	}
 * };
 * */

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};
class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
        /**
         * 链表翻转呢，通常会有两个版本，一个是循环迭代，一个是递归
         * 我们先写一个循环迭代版本的吧
         */
#if 0
        // 先检验参数合法性
        if (pHead == nullptr)
        {
            return nullptr;
        }
        ListNode* pPre = nullptr;
        ListNode* pCur = pHead;
        ListNode* pNext = pHead->next; // 这一步一定不会出问题的，我们前面判断过了，pHead不为nullptr
        
        while (pCur)
        {
            pCur->next = pPre;
            pPre = pCur;
            pCur = pNext;
            if(pNext == nullptr)
            {
                break;
            }
            pNext = pNext->next;
        }
        return pPre;
#endif
        /**
         * 接下来实现一个递归版本的
         * 递归实现的思路是：
         *    如果当前节点的next不为空，就递归
         *    如果当前节点的next为空，就返回当前节点
         *    回溯过程：让当前节点的next（下一个节点）的next指向当前节点，然后将当前节点的next置空
         *            然后返回 递归返回的那个节点（头节点）
         */ 
        if (pHead == nullptr)
        {
            return nullptr;
        }
        return assist(pHead);
    }
private:
    ListNode* assist(ListNode* pHead);
};

// 考虑到默认inline属性 我还是把成员函数的声明和定义分开了
ListNode* Solution::assist(ListNode* pHead)
{
    if (pHead->next == nullptr)
    {
        return pHead;
    }
    
    ListNode* head = assist(pHead->next);
    pHead->next->next = pHead;
    pHead->next = nullptr;
    
    return head;
}

