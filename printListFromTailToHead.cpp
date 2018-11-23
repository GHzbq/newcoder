/*
 * 输入一个链表，按链表值从尾到头的顺序返回一个ArrayList。
 * */

#include <iostream>
#include <vector>

/**
 * *  struct ListNode {
 * *        int val;
 * *        struct ListNode *next;
 * *        ListNode(int x) :
 * *              val(x), next(NULL) {
 * *        }
 * *  };
 * */


struct ListNode 
{
    int val;
    struct ListNode *next;
    ListNode(int x) 
        :val(x)
         , next(NULL) 
    {}
};

class Solution {
public:
    std::vector<int> printListFromTailToHead(ListNode* head)
    {
        std::vector<int> res;
        while(head != nullptr)
        {
            res.insert(res.begin(), head->val);
            head = head->next;
        }

        return res;
    }
};
