#include<iostream>
using namespace std;
#define MAX 10
class Stack {
    int top;
public:
    int a[MAX];
    Stack(){top=-1;}
    bool isEmpty();
    void push(int x);
    int pop();
    int peek();
    void display ()
    {
        int i;
        cout<<"Stack is : \n\n";
        for (i=top;i>-1;i--)
        {
           cout<<a[i]<<endl;
        }
    }
    void revdisplay ()
    {
        int i;
        cout<<"Reverse of the Stack is : \n";
        for (i=0;i<top+1;i++)
        {
            cout<<a[i]<<endl;
        }
    }
};
bool Stack::isEmpty()
{
    if (top==-1)
    {
        return true;
    }
}
void Stack::push(int x)
{
    if (top==MAX-1)
    {
        cout<<"Stack Overflow"<<endl;
    }
    else
    {
        a[++top]=x;
        cout<<x<<" Has been pushed to the stack"<<endl;
    }
}
int Stack::pop()
{
    int x;
    if (top<0)
    {
        cout<<"Stack Underflow"<<endl;
    }
    else
    {
        x=a[top--];
        return x;
    }
}
int Stack :: peek()
{
    int x;
    if (top<0)
    {
        cout<<"Stack Empty"<<endl;
    }
    else
    {
        x=a[top];
        return x;
    }
}
int main ()
{
    class Stack s;
    s.push(10);
    cout<<endl;
    s.push(20);
    cout<<endl;
    s.push(30);
    cout<<endl;
    s.push(40);
    cout<<endl;
    s.push(50);
    cout<<endl;
    s.push(60);
    cout<<endl;
    cout<<s.pop()<<" Has been popped from the stack."<<endl;
    cout<<endl;
    cout<<s.peek()<<" is in the top of stack.\n"<<endl;
    s.display();
    cout<<endl<<endl;
    s.revdisplay();
}

