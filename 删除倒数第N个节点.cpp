#include"iostream"
using namespace std;

struct LinkNode
{
    int val;
    LinkNode *next;
    LinkNode(int x) : val(x), next(NULL) {}
};

LinkNode *demo(LinkNode *head,int n){
    LinkNode *dummyHead = new LinkNode(0);
    dummyHead->next=head;
    LinkNode *fast=dummyHead;
    LinkNode *slow=dummyHead;
    n++;
    while(n--&&fast!=NULL){
        fast = fast->next;
    }
    while(fast!=NULL){
        fast=fast->next;
        slow=slow->next;
    }
    LinkNode *delNode = slow->next;
    slow->next = slow->next->next;
    delete delNode;
    return dummyHead->next;
}