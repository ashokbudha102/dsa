#include<iostream>
#include<string>
using namespace std;
#define MAX 5
class Stack {
    int top;

public:
    int sta[MAX];
    Stack() { top = -1; }
    void push(char x);
    char pop();
    char peek();
    bool isEmpty();
};


void Stack::push(char x)
{
    if (top >= (MAX - 1)) {
        cout << "Stack Overflow"<<endl;
    }
    else {
        sta[++top] = x;

    }
}

char Stack::pop()
{
    if (top < 0) {
        cout << "Stack Underflow"<<endl;
        return 0;
    }
    else {
        char x = sta[top--];
        return x;
    }
}
char Stack::peek()
{
    if (top < 0) {
        cout << "Stack is Empty\n";
        return 0;
    }
    else {
        char x = sta[top];
        return x;
    }
}
bool Stack::isEmpty()
{
    if(top<0)
    {
        return true;

    }
    else{
        return false;
    }
}
int main()
{
    Stack s;
    string exp;
    cout<<"Enter a mathematical expression\n"<<endl;
    cin>>exp;
    for(int i=0;i<20;i++)
    {
        if (exp[i]=='(')
                s.push(exp[i]);
        else if (exp[i]==')')
            s.pop();
        else
                continue;

    }
    if(s.isEmpty())
    {
        cout<<"The given expression is valid in terms of paranthesis \n"<<endl;
    }
    else{

        cout<<"The given expression is not valid in terms of paranthesis \n"<<endl;
    }


}
