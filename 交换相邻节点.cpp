#include "iostream"
#include "vector"
using namespace std;

struct LinkNode
{
    int val;
    LinkNode *next;
    LinkNode(int x) : val(x), next(NULL) {}
};

LinkNode *demo(LinkNode *head)
{
    LinkNode *dummyHead = new LinkNode(0);
    dummyHead->next = head;
    LinkNode *cur = dummyHead;
    while (cur->next != NULL && cur->next->next != NULL)
    {
        LinkNode *node1 = cur->next;
        LinkNode *node2 = cur->next->next;
        cur->next = cur->next->next;
        cur->next->next = node1;
        node1->next = node2;
        cur = cur->next->next;
    }
    return dummyHead->next;
}