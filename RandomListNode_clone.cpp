/* 复杂链表的复制
 * 输入一个复杂链表（每个节点中有节点值，以及两个指针，一个指向下一个节点，
 * 另一个特殊指针指向任意一个节点），返回结果为复制后复杂链表的head。
 * （注意，输出结果中请不要返回参数中的节点引用，否则判题程序会直接返回空）
 *
 * 题目链接：https://www.nowcoder.com/practice/f836b2c43afc4b35ad6adc41ec941dba?tpId=13&tqId=11178&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
 *
 * */
struct RandomListNode {
	int label;
	struct RandomListNode *next, *random;
	
	RandomListNode(int x) :
	label(x), next(NULL), random(NULL) 
	{}
};

class Solution {
public:
	RandomListNode* Clone(RandomListNode* pHead)
	{
		if (pHead == nullptr)
		{
			return nullptr;
		}
		// 先在源链表的基础上复制一份，不拆开
		// random指针只能指向链表上的某个节点或者空
		RandomListNode * pcur = pHead;
		RandomListNode * pnew = nullptr;
		while (pcur)
		{
			pnew = new RandomListNode(pcur->label);
			pnew->next = pcur->next;
			pcur->next = pnew;
			pcur = pnew->next;
		}
		// 循环走到这儿，所有的节点已经被复制
		// 接下来我们考虑以前随机指针的指向
		// 我们可以画图分析，
		// 上面步骤的复制过程，我们没有修改random指向
		// 因为不知道怎么修改，当我们复制完整个链表之后，新添加节点的random指针是指向空的
		// 复制完了之后可以修改了，
		// 如果原random指针非空，让新节点的random指针指向原random指针的下一个节点
		// 如果是空的，就不管
		pcur = pHead;
		RandomListNode* ret = pHead->next;
		RandomListNode* pret = ret;
		while (pcur)
		{
			if (pcur->random)
			{
				pret->random = pcur->random->next;
			}
			pcur = pret->next;
			if (pcur == nullptr)
			{
				break;
			}
			pret = pcur->next;
		}

		// 到此我们已经完成复制工作，接下来就是拆开了
		// 拆也比较简单，random指针已经指向新节点，只需拆掉next，并且不破坏原链表结构即可
		pcur = pHead;
		pret = ret;
		while (pret)
		{
			pcur->next = pret->next;
			if (pret->next)
			{
				pret->next = pcur->next->next;
			}
			pcur = pcur->next;
			pret = pret->next;
		}
		// 等这圈循环走完，链表就拆开äº
		return ret;
	}
};
