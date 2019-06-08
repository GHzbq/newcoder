/* 复杂链表的复制
 * 输入一个复杂链表（每个节点中有节点值，以及两个指针，一个指向下一个节点，
 * 另一个特殊指针指向任意一个节点），返回结果为复制后复杂链表的head。
 * （注意，输出结果中请不要返回参数中的节点引用，否则判题程序会直接返回空）
 *
 * 题目链接：https://www.nowcoder.com/practice/f836b2c43afc4b35ad6adc41ec941dba?tpId=13&tqId=11178&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
 *
 * */
#include <iostream>

struct RandomListNode {
	int label;
	struct RandomListNode *next, *random;
	
	RandomListNode(int x) :
	label(x), next(NULL), random(NULL) 
	{}
};

// 以下为 2019.06.08 更新
/*
struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};
*/

class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead)
    {
        /**
         * 关于复杂链表的复制 分为三步吧
         * 1. 先将链表的每个节点复制
         *    怎么复制：创建一个与当前节点一样的节点，并且链接在当前节点之后，
         *              random指针先不管，新节点的next必须指向当前节点的next
         *              这是必须得嘛，总不能把新节点链上，而将原来的节点丢弃
         *  2. 修改新节点的random指针指向
         *     其实我们发现一个很神奇的现象就是，经过我们第一步的复制，
         *     原节点的random指针指向节点的next，恰好应该是新节点random指针所指向的节点
         *  3. 将链表拆开
         *     也就是将链表分为两个链表吧，原链表和新复制的链表
         */
        // 我们做一个大胆的尝试，直接将 pHead 返回会怎样？
        // return pHead; // 遗憾的是，并不能这么投机取巧，还是老老实实干活吧
        
        // 还是老规矩，先检验参数合法性
        if (nullptr == pHead)
        {
            return nullptr;
        }
        
        // 1. 先将原链表的每个节点复制
        RandomListNode* pCur = pHead;
        RandomListNode* pNext = pHead->next;
        RandomListNode* pNewNode = nullptr;
        // 这样是有问题的 最后一个节点没有复制
        // while(pNext)
        // {
        //     pNewNode = new RandomListNode(pCur->label);
        //     pNewNode->next = pNext;
        //     pCur->next = pNewNode;
        //     // 这里需要考虑边界条件
        //     pCur = pNext; // 这一步并不会出现问题呀
        //     pNext = pCur->next; // pCur 存在 取pCur->next 应该也是没有问题的
        // }
        while (pCur)
        {
            pNewNode = new RandomListNode(pCur->label);
            pNewNode->next = pCur->next;
            pCur->next = pNewNode;
            pCur = pNewNode->next;
        }
        
        // 2. 修改新节点 random 指针的指向
        pCur = pHead;
        pNext = pCur->next;
        while (pNext)
        {
            // 这一步可能出现问题，因为随机指针可能指向 nullptr
            // pNext->random = pCur->random->next;
            if (pCur->random)
            {// random指针存在 才修改新节点random指针指向，否则指向nullptr，不需要修改
                pNext->random = pCur->random->next;
            }
            pCur = pNext->next; // 只要保证 pNext 有效 pNext->next 不会出现问题
            // 但是此时取 pCur->next 可能出现问题 所以我们需要判断一下
            if (pCur)
            {
                pNext = pCur->next; // 这样绝不会出现问题
            }
            else
            {// 如果 pCur 已经为空，证明走到末尾 已经没必要继续循环
                break;
            }
        }
        
        // 3. 将复制后的链表拆开
        // 我们需要一个指针来保存新链表的头节点
        RandomListNode* head = pHead->next;
        pCur = pHead;
        pNext = pCur->next;
        while(pNext)
        {
            pCur->next = pNext->next;
            // 修改 pNext->next 可能会有麻烦 我们需要考虑边界条件
            pCur = pNext->next;
            if (pCur)
            {
                pNext->next = pCur->next;
                pNext = pCur->next;
            }
            else
            { // 其实这一步有没有都可以
                pNext->next = nullptr;
            }
        }
        
        return head;
    }
};

// 以上为 2019.06.08 更新

// class Solution {
// public:
// 	RandomListNode* Clone(RandomListNode* pHead)
// 	{
// 		if (pHead == nullptr)
// 		{
// 			return nullptr;
// 		}
// 		// 先在源链表的基础上复制一份，不拆开
// 		// random指针只能指向链表上的某个节点或者空
// 		RandomListNode * pcur = pHead;
// 		RandomListNode * pnew = nullptr;
// 		while (pcur)
// 		{
// 			pnew = new RandomListNode(pcur->label);
// 			pnew->next = pcur->next;
// 			pcur->next = pnew;
// 			pcur = pnew->next;
// 		}
// 		// 循环走到这儿，所有的节点已经被复制
// 		// 接下来我们考虑以前随机指针的指向
// 		// 我们可以画图分析，
// 		// 上面步骤的复制过程，我们没有修改random指向
// 		// 因为不知道怎么修改，当我们复制完整个链表之后，新添加节点的random指针是指向空的
// 		// 复制完了之后可以修改了，
// 		// 如果原random指针非空，让新节点的random指针指向原random指针的下一个节点
// 		// 如果是空的，就不管
// 		pcur = pHead;
// 		RandomListNode* ret = pHead->next;
// 		RandomListNode* pret = ret;
// 		while (pcur)
// 		{
// 			if (pcur->random)
// 			{
// 				pret->random = pcur->random->next;
// 			}
// 			pcur = pret->next;
// 			if (pcur == nullptr)
// 			{
// 				break;
// 			}
// 			pret = pcur->next;
// 		}
// 
// 		// 到此我们已经完成复制工作，接下来就是拆开了
// 		// 拆也比较简单，random指针已经指向新节点，只需拆掉next，并且不破坏原链表结构即可
// 		pcur = pHead;
// 		pret = ret;
// 		while (pret)
// 		{
// 			pcur->next = pret->next;
// 			if (pret->next)
// 			{
// 				pret->next = pcur->next->next;
// 			}
// 			pcur = pcur->next;
// 			pret = pret->next;
// 		}
// 		// 等这圈循环走完，链表就拆开äº
// 		return ret;
// 	}
// };
