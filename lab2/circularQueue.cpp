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
        if (front==-1)
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
        if((front==0&&rear==MAX-1)||(front==rear+1))
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
        }
        else
        {
            if(front==-1&&rear==-1)
            {
                front=0;
                rear=0;
            }
            else
            {
                if(rear==MAX-1)
                {
                    rear=0;

                }
                else
                {
                    rear=rear+1;
                }
            }

            queue[rear]=a;
            cout<<queue[rear]<<" pushed to queue"<<endl;
        }


    }
    int dequeue()
    {
        int temp=-1;
        if(isEmpty())
        {

            cout<<"queue is empty"<<endl;
            return temp;
        }
        else{
                temp=queue[front];
                if(front==rear)
                {
                    front=-1;
                    rear=-1;
                }
                else
                {
                    if(front==MAX-1)
                    {
                        front=0;
                    }
                    else{
                        front=front+1;
                    }
    }
        }
        return temp;

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
        Queue temp=q;
        int count=0;
        cout<<"\n\n\n"<<endl;
        while(!temp.isEmpty())
        {
            count+=1;
            cout<<temp.dequeue()<<endl;

        }
        cout<<"The no.of items is ="<<count<<endl;
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
