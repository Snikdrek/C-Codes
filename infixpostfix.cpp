#include<bits/stdc++.h>
using namespace std;
#define MAX 100
char stack[MAX];
char infix[100];
char postfix[100];
int top=-1;
void push(char item)
{
    if(top==MAX-1)
    {
        cout<<"Stack Overflow\n";
        return;
    }
    top=top+1;
    infix[top]=item;
}
void intopost()
{
    int i;
    char symbol;
    for(i=0;i<strlen(infix);i++)
    {
        symbol=infix[i];
        switch (symbol)
        {
        case '(':
            push(symbol);
            break;


                }
    }
}
//recursion factorial
int fact(int n)
{
    if(n==0)
    {
        return 1;
    }
    else
    {
        return n*fact(n-1);
    }
}
//recursion fibonacci
int fib(int n)
{
    if(n==0)
    {
        return 0;
    }
    else if(n==1)
    {
        return 1;
    }
    else
    {
        return fib(n-1)+fib(n-2);
    }
}
int main()
{
    cout<<"Enter the infix expression\n";
    gets(infix);
}
