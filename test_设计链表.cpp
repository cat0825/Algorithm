#include"iostream"
#include"vector"
using namespace std;
class MyLinkedList{
    struct LinkNode{
        int val;
        LinkNode *next;
        LinkNode(int val):val(val),next(NULL){}
    };
    public:
    	int size;
    	LinkNode *dummyHead;
    MyLinkedList(){
        dummyHead=new LinkNode(0);
        size=0;
    }
    
    //获取索引对应的值
    int get(int index){
        LinkNode *cur=dummyHead->next;
        if(index>(size-1)||index<0)
            return -1;
        while(index--){
            cur=cur->next;
        }
        return cur->val;
    }
    //在头节点之前添加一个节点
    void addAtHead(int val){
        LinkNode *newNode=new LinkNode(val);
        newNode->next=dummyHead->next;
        dummyHead->next=newNode;
        size++;
    }
    //在链表末尾添加一个节点
    void addAtEnd(int val){
        LinkNode *newNode=new LinkNode(val);
        LinkNode *cur=dummyHead->next;
        while(cur->next!=NULL){
            cur=cur->next;
        }
        cur->next=newNode;
        size++;
    }
    //在索引位置插入元素
    void addAtIndex(int val,int index){
        if(index>(size-1)||index<0)
            return;
        if(index==1){
            LinkNode *newNode=new LinkNode(val);
            newNode->next=dummyHead->next;
        }
        LinkNode *pre=NULL;
        LinkNode *cur=dummyHead->next;
        for(int i=0;i<index;i++){
            pre=cur;
            cur=cur->next;
            if(cur==NULL){
                cout<<"索引参数有误!"<<endl;
                return;
            }
        }
        LinkNode *newNode=new LinkNode(val);
        newNode->next=cur;
        pre->next=newNode;
    }
    //打印链表
    void printList(LinkNode *head){
        LinkNode *cur=head;
        while(cur!=NULL){
            cout<<cur->val<<" ";
            cur=cur->next;
        }
        cout<<endl;
    }
    
};

int main(){
    MyLinkedList *obj=new MyLinkedList();
    obj->addAtHead(1);
    obj->addAtEnd(3);
    obj->addAtIndex(2,2);
    obj->printList(obj->dummyHead->next);
    cout<<obj->get(1)<<endl;
    return 0;
}