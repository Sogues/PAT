/**
 *
 *  File Name: main.cpp
 *  brief:
 *  Create Time: 2018年04月24日 13:50:05
 *
 */

/**
 *  题目大意:
 *	That is, for each value K, only the first node of which the value or absolute value of its key equals K will be kept
 *	上述意思就是， 对于每一个k，仅保留首次出现的k，以后出现的都进行remove
 *	需求：输出去重后的list，并且保留按顺序被去重的node
 */

/**
 *  输入：
 *		首行：首节点的地址 总的节点数N
 *			-- 地址格式：有效地址为5为非负数字，无效NULL为-1
 *			-- N <= 10^5
 *		N行：地址 key值 next地址
 *			-- key值 <= 10^4
 */

/**
 *  输出：
 *		输出去重后的list，然后接着输出去重后的list
 *		每个node占据一行，与输入格式相同
 */

#include <cstdio>
#include <iostream>
#include <map>
#include <vector>

const uint32_t max_key = 10001;
const uint32_t max_addr = 100001;
struct Node
{
	int32_t addr;
	int32_t key;
	int32_t next;
}node_pack[max_addr];


uint32_t _abs(int key)
{
	return key >= 0 ? key : -key;
}

int main ()
{
	int32_t head = -1, N = 0;
	scanf("%d %d", &head, &N);
	int32_t key_count[max_key] = {0};
	std::vector<int32_t> remove_ans;
	for (int32_t i = 0; i != N; ++i)
	{
		Node _tmp;
		scanf("%d %d %d", &_tmp.addr, &_tmp.key, &_tmp.next);
		/* 忽视重复地址 */
		node_pack[_tmp.addr] = _tmp;
		key_count[_abs(_tmp.key)] += 1;
	}

	//std::cout << "==============="<<std::endl;
	int tail = -1;
	while (head != -1)
	{
		if (key_count[_abs(node_pack[head].key)] == 0)
		{
			remove_ans.push_back(head);
		}
		else
		{
			if (tail != -1)
			{
				printf(" %05d\n", tail);
			}
			printf("%05d %d", head, node_pack[head].key);
			key_count[_abs(node_pack[head].key)] = 0;
		}
		head = node_pack[head].next;
		tail = head;
		if (tail == -1)
		{
			printf(" -1\n");
		}
	}
	tail = -1;
	for (int idx = 0; idx != remove_ans.size(); ++idx)
	{
		if (tail != -1)
		{
			printf(" %05d\n", tail);
		}
		printf("%05d %d", node_pack[remove_ans[idx]].addr, node_pack[remove_ans[idx]].key);
		if (idx + 1 == remove_ans.size())
		{
			printf(" -1\n");
			break;
		}
		tail = node_pack[remove_ans[idx+1]].addr;
	}

	return 0;
}

