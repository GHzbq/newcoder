/**
 * 合并两个排序的链表
 * nowcoder: https://www.nowcoder.com/practice/d8b6b4358f774294a89de2a6ac4d9337?tpId=13&tqId=11169&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
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
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        // 首先检查参数的合法性
        if (!pHead1)
        {
            return pHead2;
        }
        
        if (!pHead2)
        {
            return pHead1;
        }
        
        // 之后开始合并呗
        ListNode* head = nullptr;
        ListNode* tail = nullptr;
        if (pHead1->val < pHead2->val)
        {
            head = pHead1;
            tail = head;
            pHead1 = pHead1->next;
        }
        else
        {
            head = pHead2;
            tail = head;
            pHead2 = pHead2->next;
        }
        
        while (pHead1 && pHead2)
        {
            if (pHead1->val < pHead2->val)
            {
                tail->next = pHead1;
                tail = pHead1;
                pHead1 = pHead1->next;
            }
            else
            {
                tail->next = pHead2;
                tail = pHead2;
                pHead2 = pHead2->next;
            }
        }
        
        // 假如pHead1还没有处理完
        if (pHead1)
        {
            tail->next = pHead1;
        }
        // 假如pHead2还没有处理完
        if (pHead2)
        {
            tail->next = pHead2;
        }
        
        return head;
    }
};
