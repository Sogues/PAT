#if 0
题目大意：
    you are supposed to sort the structures according to their key values in increasing order.
    即对链表按key值进行升序排序
输入：
    首行：总节点数N 首地址
        --N < 10^5
        --地址 5位非负数字，null为-1
    N行：地址 key值 next
        --key -10^5 <= key <= 10^5 所有key值保证唯一
        --next 保证从head节点开始的链表没有循环
输出：
    首行：有效链表的总数 首地址
    N行：按输入格式一次输出有效节点
.
#endif
#include <iostream>
#include <map>
#include <cassert>

const uint32_t max_id = 100001;
struct Node
{
    Node():addr(-1), key(0), next(-1), valid(false)
    {
    }
    int32_t addr;
    int32_t key;
    int32_t next;
    bool valid;
}Node[max_id];

int main()
{
    int32_t N, head;
    std::cin >> N >> head;
    for (int32_t i = 0; i != N; ++i)
    {
        int _addr, _key, _next;
        std::cin >> _addr >> _key >> _next;
        Node[_addr].addr = _addr;
        Node[_addr].key = _key;
        Node[_addr].next = _next;
    }
    int32_t tmp_head = head;
    std::map<int32_t, int32_t>  sort_map;
    while (tmp_head != -1)
    {
        sort_map[Node[tmp_head].key] = tmp_head;
        tmp_head = Node[tmp_head].next;
    }
    auto find_iter = sort_map.begin();
    int32_t map_size = sort_map.size();
    if (find_iter == sort_map.end())
    {
        printf("0 -1\n");
        return 0;
    }
    printf("%d %05d\n", map_size, find_iter->second);

    int32_t index = 0;
    for (auto item : sort_map)
    {
        if (index != 0)
        {
            printf(" %05d\n", item.second);
        }
        printf("%05d %d", item.second, item.first);
        if (++index == map_size)
        {
            printf(" -1\n");
        }
    }
    return 0;
}
