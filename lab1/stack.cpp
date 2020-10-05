#include<iostream>
using namespace std;
#define MAX 5
class Stack {
    int top;

public:
    int sta[MAX];
    Stack() { top = -1; }
    void push(int x);
    int pop();
    int peek();
};

void Stack::push(int x)
{
    if (top >= (MAX - 1)) {
        cout << "Stack Overflow"<<endl;
    }
    else {
        sta[++top] = x;
        cout << x << " pushed in stack \n";

    }
}

int Stack::pop()
{
    if (top < 0) {
        cout << "Stack Underflow"<<endl;
        return 0;
    }
    else {
        int x = sta[top--];
        return x;
    }
}
int Stack::peek()
{
    if (top < 0) {
        cout << "Stack is Empty\n";
        return 0;
    }
    else {
        int x = sta[top];
        return x;
    }
}

int main()
{
   Stack s;
    s.push(1);
    s.push(2);
    cout << s.peek()<<"is in top of stack"<<endl;
    s.push(3);
    s.push(7);
    s.push(8);
    s.push(9);
    cout << s.pop() << "is popped\n";
    cout << s.pop() << "is popped\n";
    cout << s.pop() << "is popped\n";
    cout << s.peek();
    return 0;

}
