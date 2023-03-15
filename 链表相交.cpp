#include "iostream"
using namespace std;
struct LinkNode
{
    int val;
    LinkNode *next;
    LinkNode(int x) : val(x), next(NULL) {}
};

LinkNode *demo(LinkNode *headA, LinkNode *headB)
{
    LinkNode *curA=headA;
    LinkNode *curB=headB;
    int lenA = 0;
    int lenB = 0;
    while (headA != NULL)
    {
        lenA++;
        headA = headA->next;
    }
    while (headB != NULL)
    {
        lenB++;
        headB = headB->next;
    }
    if (lenB > lenA)
    {
        swap(lenA, lenB);
        swap(curA, curB);
    }
    int gap = lenA - lenB;
    while(gap--){
        curA = curA->next;
    }
    while(curA!=NULL){
        if(curA==curB){
            return curA;
        }else{
            curA=curA->next;
            curB=curB->next;
        }
    }
    return NULL;
}