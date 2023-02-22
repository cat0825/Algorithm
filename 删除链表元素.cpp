#include "iostream"
#include "vector"
using namespace std;

struct LinkNode
{
    int val;
    LinkNode *next;
    LinkNode(int x) : val(x), next(NULL) {}
};

LinkNode *deleteElements(LinkNode *head, int target)
{
    // 删除头节点
    while (head != NULL && head->val == target)
    {
        LinkNode *temp = head;
        head = head->next;
        delete temp;
    }
    // 删除非头节点
    LinkNode *cur=head;
    while(cur!=NULL&&cur->next!=NULL){
        if(cur->next->val==target){
            LinkNode *temp = cur->next;
            cur->next=temp->next;
            delete temp;
        }else{
            cur = cur->next;
        }
    }
    return head;

}

LinkNode* removeElements(LinkNode* head,int val){
    LinkNode *dummyNode = new LinkNode(-1);
    dummyNode->next = head;
    LinkNode *cur = dummyNode;
    while(cur->next!=NULL){
        if(cur->next->val==val){
            LinkNode *temp = cur->next;
            cur->next = temp->next;
            delete temp;
        }else{
            cur = cur->next;
        }
    }
    head = dummyNode->next;
    delete dummyNode;
    return head;
}
