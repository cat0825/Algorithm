#include"iostream"
#include"vector"
using namespace std;

struct LinkNode
{
    int val;
    LinkNode* next;
    LinkNode(int x) :val(x), next(NULL) {}
};


 LinkNode* demo(LinkNode *head){
    LinkNode *cur=head;
    LinkNode *pre = NULL;
    LinkNode *temp;
    while(cur){
        temp = cur->next;
        cur = pre;
        pre = cur;
        cur = temp;
    }
    return pre;
}

//递归方法