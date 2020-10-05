#include<iostream>
using namespace std;
#define MAX 3
class Queue
{
    int queue[MAX],front, rear;
public:
    Queue()
    {
        front=-1;
        rear=-1;
    }
    bool isEmpty()
    {
        if (front==-1||front>rear)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool isFull()
    {
        if(rear==MAX-1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void enqueue(int a)
    {
        if (isFull())
        {
            cout<<"Queue is Full "<<endl;
            return;
        }
        else{
        if(front==-1)
            front=0;
        queue[++rear]=a;
        cout<<queue[rear]<<" pushed to queue"<<endl;

        }
    }
    int dequeue()
    {
        if(isEmpty())
        {

            cout<<"queue is empty"<<endl;
            return -1;
        }
        int data=queue[front++];

        return data;

}

};
void menu()
{
    Queue q;
    char choice;
    while (choice!='3')
    {
        cout<<"\n\n\n\n\n\n\n\n\n"<<endl;
       cout<<"____________MENU____________________"<<endl;
    cout<<"1. Enqueue an element\n"<<endl;
    cout<<"2. Dequeue an element\n"<<endl;
    cout<<"3. Display all elements\n"<<endl;
    cout<<"4. Exit\n"<<endl;
    cout<<"enter a choice \t"<<endl;
    cin>>choice;

    if(choice=='1')
    {
        int n;
        cout<<"Enter an element to be enqueued"<<endl;
        cin>>n;
                    cout<<"\n\n\n"<<endl;
        q.enqueue(n);
    }
    else if(choice=='2')
    {
            cout<<"\n\n\n"<<endl;
        cout<<"the dequeued element is"<<q.dequeue();

    }
    else if(choice=='4')
    {
        break;
    }
    else if(choice=='3')
    {
        int count=0;
        Queue temp=q;
        cout<<"\n\n\n"<<endl;
        while(!temp.isEmpty())
        {
            count+=1;
            cout<<temp.dequeue()<<endl;
        }
        cout<<"The no.of elements is "<<count<<endl;
    }
    else{
        cout<<"enter a valid expression"<<endl;
    }
    }

}
int main()
{
menu();
}
