/**
 * 链表的倒数第K个节点
 * nowcoder: https://www.nowcoder.com/practice/529d3ae5a407492994ad2a246518148a?tpId=13&tqId=11167&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
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
 **/
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};
class Solution {
public:
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        /**
         * 我们不妨先检验参数的合法性吧，要是参数都不合法，还有什么好做的
         */
        if (pListHead == nullptr)
        {
            return nullptr;
        }
        unsigned int count = 0; // 统计链表节点个数
        ListNode* pCur = pListHead;
        while(pCur)
        {
            ++count;
            pCur = pCur->next;
        }
        if (count < k)
        {
            return nullptr;
        }
        
        // 参数检验合格
        /**
         * 双指针解决吧：
         * first 指针先走 k 步 
         * 然后 first 和 second 一起走，当 first 走到末尾的时候，
         * 返回 second 指向的节点
         */
        ListNode* first = pListHead;
        ListNode* second = pListHead;
        while(k--)
        {
            first = first->next;
        }
        // 然后两个指针一起走
        while(first)
        {
            first = first->next;
            second = second->next;
        }
        return second;
    }
};
