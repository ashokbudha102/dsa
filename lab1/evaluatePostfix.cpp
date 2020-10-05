//evaluate a given postfix expression using a stack
#include<iostream>
#define MAX 20
using namespace std;
class Stack {

        int top;
public:

    int sta[MAX];
    Stack() { top = -1; }
    void push(char x);
    int pop();
    int peek();
    bool isEmpty();
};
void Stack::push(char x)
{
    if (top >= (MAX - 1)) {
            return;
    }
    else {
        sta[++top] = x;

    }
}

int Stack::pop()
{
    if (top < 0) {
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
int evaluatePostfix(string exp)
{
    Stack s;
    for(int i=0;exp[i];++i)
    {
        if (exp[i]==' ')
            continue;
        else if (isdigit(exp[i]))
        {
            int num=0;
            while(isdigit(exp[i]))
            {
                num=num*10+(int)(exp[i]-'0');
                cout<<num<<endl;
                i++;
                cout<<"value of i"<<i<<endl;
            }
            s.push(num);
            i--;

        }
        else
        {
            int val1=s.pop();
            int val2=s.pop();
            switch(exp[i])
            {
            case '+':
                s.push(val2+val1);
                break;
            case '-':
                s.push(val2-val1);
                break;
            case '*':
                s.push(val2*val1);
                break;
            case '/':
                s.push(val2/val1);
                break;
            case '^':
                s.push(val2^val1);
                break;

            }
        }


    }

int result=s.pop();
return result;
}
int main()
{
    string exp;
    cout<<"enter a postfix expression to be evaluated"<<endl;
    cin>>exp;
    int result=evaluatePostfix(exp);
    cout<<"final result"<<result<<endl;
    return 0;

}

