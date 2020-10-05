//conversion of infix expression to postfix expression using stack
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
            return;
    }
    else {
        sta[++top] = x;

    }
}

char Stack::pop()
{
    if (top < 0) {
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
int compareAssociativity(char c)
{
    if (c=='+'||c=='-')
        return 1;
    else if(c=='*'||c=='/')
        return 2;
    else if(c=='^')
        return 3;
    else
        return -1;


}
string reverseExp(string exp)
{
    string newExp;
    for(int i=0;i<exp.length();i++)
    {
        if(exp[i]=='(')
            newExp=')'+newExp;
        else if(exp[i]==')')
            newExp='('+newExp;
        else
        {
           newExp=exp[i]+newExp;
        }

    }
    return newExp;
}
string ConvertPrefix(string exp)
{
    Stack s;
    s.push('N');

        string postfix;
    for(int i=0;i<exp.length();i++)
    {
        if (exp[i]>='a' && exp[i]<='z')
        {
            postfix+=exp[i];
        }
        else if (exp[i]=='(')
                    s.push('(');
        else if (exp[i]==')')
        {
            while(s.peek()!='(' && s.peek()!='N')
            {
                char c =s.peek();
                s.pop();
                postfix+=c;
            }
            if(s.peek()=='('){
                char c=s.peek();
                s.pop();
               }
        }
        else{
                while(s.peek()!='N' && compareAssociativity(exp[i])<=compareAssociativity(s.peek()))
                {
                    char c=s.peek();
                     s.pop();
                    postfix+=c;

                }
                s.push(exp[i]);
            }



    }
    while(s.peek()!='N')
    {
        char c=s.peek();
        s.pop();
        postfix+=c;
    }
    return postfix;


}
int main()
{
    string exp;
    cout<<"Enter a infix expression to be evaluated:"<<endl;
    cin>>exp;
    string newexp=reverseExp(exp);
    string prefix=ConvertPrefix(newexp);
    cout<<"The equivalent postfix expression is ="<<reverseExp(prefix)<<endl;
}
