#include<iostream>
using namespace std;
struct ListNode{
int data;
struct ListNode *next;
};

void pushBeginning(ListNode **head, int data)
{
    ListNode *newNode=new ListNode();
    if(newNode==NULL)
    {
        cout<<"memory allocation not successful"<<endl;
        return;
    }
    newNode->data=data;
    newNode->next=(*head);
    *head=newNode;
}
void pushEnd(ListNode **head, int data)
{
    ListNode *newNode=new ListNode();
    if(newNode==NULL)
    {
        cout<<"memory allocation not successful"<<endl;
        return;
    }
    newNode->data=data;
    newNode->next=NULL;
    ListNode *temp= *head;
    while(temp->next!=NULL)
    {
        temp=temp->next;

    }
    temp->next=newNode;
}
void pushBefore(ListNode **head, int data, int given)
{
    ListNode *newNode=new ListNode();
    newNode->data=data;
    ListNode *ptr=*head;
    ListNode *preptr=ptr;
    while(ptr->data!=given)
    {
        preptr=ptr;
        ptr=ptr->next;
    }
    preptr->next=newNode;
    newNode->next=ptr;

}
void pushAfter(ListNode **head, int data1, int after)
{
    ListNode *newNode=new ListNode();
    newNode->data=data1;
    ListNode *ptr=*head;
    ListNode *preptr=ptr;
    while(preptr->data!=after)
    {
        preptr=ptr;
        ptr=ptr->next;
    }
    preptr->next=newNode;
    newNode->next=ptr;
}
void displayList(ListNode **head)
{
    ListNode *temp=*head;
    cout<<"Displaying LIST"<<endl;
    while(temp!=NULL)
    {
        cout<<temp->data<<endl;
        temp=temp->next;
    }
    return;
}
/*void deleteNode(ListNode **head,int data)
{
    if(*head==NULL)
    {
        cout<<"The node doesn't exist"<<endl;
        return;
    }
    struct ListNode *temp=
}*/
int main()
{
    ListNode* head=NULL;
    pushBeginning(&head, 4);
    pushEnd(&head, 5);
    displayList(&head);
    pushBefore(&head, 10, 5);
    displayList(&head);
    pushAfter(&head, 12, 10);
    displayList(&head);

}
