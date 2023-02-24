#include "iostream"
#include "vector"
using namespace std;

class MyLinkedList
{
public:
    struct LinkNode
    {
        int val;
        LinkNode *next;
        LinkNode(int val) : val(val), next(NULL){};
    };
        LinkNode *dummyNode;
        int size;
        MyLinkedList()
        {
            dummyNode = new LinkNode(-1);
            size = 0;
        }
        int getElem(int index){
            if(index>(size-1)||index<0){
                return -1;
            }
            LinkNode *cur = dummyNode->next;
            while(index--){
                cur = cur->next;
            }
            // for (int i = 0; i < index; i++){
            //     cur = cur->next;
            // }
                return cur->val;
        }
        // 在头节点之前添加一个节点
        void addAtHead(int val){
                LinkNode *newNode = new LinkNode(val);
                newNode->next = dummyNode->next;
                dummyNode->next = newNode;
                size++;
        }
        // 在链表的最后添加一个节点
        void addAtEnd(int val){
            LinkNode *newNode = new LinkNode(val);
            LinkNode *cur = dummyNode;
            while(cur->next!=NULL){
                cur = cur->next;
            }
            cur->next = newNode;
            size++;
        }
        // 在链表的第index个节点之前添加一个节点
        void addAtIndex(int index,int val){
            if(index>size){
                return;
            }
            if(index<=0){
                return;
            }
            LinkNode *newNode = new LinkNode(val);
            LinkNode *cur = dummyNode;
            while(index--){
                cur = cur->next;
            }
            newNode->next = cur->next;
            cur->next = newNode;
            size++;
        }
        // 删除链表的第index个节点
        void deleteAtIndex(int index){
            if(index>(size-1)||index<0){
                return;
            }
            LinkNode *cur = dummyNode;
            while(index--){
                cur=cur->next;
            }
            LinkNode *temp = cur->next;
            cur->next = temp->next;
            delete temp;
        }

        // 打印链表
        void printLinkedList(){
            LinkNode *cur=dummyNode->next;
            while(cur!=NULL){
                cout<<cur->val<<" ";
                cur=cur->next;
            }
            cout << endl;
        }
       

};