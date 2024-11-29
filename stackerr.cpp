#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define MAX 10
int stack_arr[MAX];
int top=-1;
int stack2[MAX];
int first=-1;
bool isfull()
{
    if(top==MAX-1)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void push2(int item){
    first++;
    for(int i=first;i>0;i--)
    {
        stack2[i]=stack2[i-1];//shifting the elements to the right

    }
    stack2[0]=item;
}
void push(int item)
{
    if(isfull())
    {
        printf("Stack Overflow\n");
        return;
    }
    top=top+1;
    stack_arr[top]=item;
}

bool isempty()
{
    if(top==-1)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int pop()
{
    if(isempty())
    {
        printf("Stack Underflow\n");
        return 0;
    }
    int item=stack_arr[top];
    top=top-1;
    return item;
}
void print()
{
    int i;
    if(isempty())
    {
        printf("Stack is empty\n");
        return;
    }
    for(i=top;i>=0;i--)
    {
        printf("%d ",stack_arr[i]);
    }
    printf("\n");
}
void print2()
{
    int i;
    if(first==-1)
    {
        printf("Stack is empty\n");
        return;
    }
    for(i=first;i>=0;i--)
    {
        printf("%d ",stack2[i]);
    }
    printf("\n");

}
int pop2()
{
    int i,item;
    item=stack2[0];
    for(i=0;i<first;i++)
    {
        stack2[i]=stack2[i+1];//shifting the elements to the left
    }
    first--;
    return item;
}
int full2()
{
    if(first==MAX-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }

}
int empty2()
{
    if(first==-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int peek2()
{
    if(empty2())
    {
        printf("Stack is empty\n");
        return 0;
    }
    return stack2[0];
}
void primefactors(int n)
{
    int i=2;
    while(n>1)
    {
        while(n%i==0)
        {
            push(i);
            n=n/i;
        }
        i++;
    }
    while(top!=-1)
    {
        int item=pop();
        printf("%d ",item);
    }
}
void dectobin(int n)
{
    while(n!=0)

    {
        push(n%2);
        n=n/2;
    }
    while(top!=-1)
    {
        int item=pop();
        printf("%d ",item);
    }
}
int main()
{

    while(true)
    {
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Print\n");
        printf("6. Push2\n");
        cout<<"7. Print2"<<endl;
        cout<<"8. Pop2"<<endl;
        cout<<"111. Prime Factors"<<endl;
        cout<<"9. Peek2"<<endl;
        cout<<"10. Peek"<<endl;
        cout<<"11. Full2"<<endl;
        cout<<"12. Empty2"<<endl;
        cout<<"13. Decimal to Binary"<<endl;
        printf("4. Exit\n");
        int choice;
        printf("Enter your choice: ");
        scanf("%d",&choice);
        if(choice==1)
        {
            int item;
            printf("Enter the item to be pushed: ");
            scanf("%d",&item);
            push(item);
        }
        else if(choice==2)
        {
            int item=pop();
            printf("Popped item is: %d\n",item);
        }
        else if(choice==3)
        {
            print();
        }
        else if(choice==4)
        {
            break;
        }
        else if(choice==6)
        {
            int item;
            printf("Enter the item to be pushed: ");
            scanf("%d",&item);
            push2(item);
        }
        else if(choice==7)
        {
            print2();
        }
        else if(choice==8)
        {
            int item=pop2();
            printf("Popped item is: %d\n",item);
        }
        else if(choice==111)
        {
            int n;
            printf("Enter the number: ");
            scanf("%d",&n);
            primefactors(n);
        }
        else if(choice==9)
        {
            int item=peek2();
            printf("Peeked item is: %d\n",item);
        }
        else if(choice==10)
        {
            int item=stack_arr[top];
            printf("Peeked item is: %d\n",item);
        }
        else if(choice==11)
        {
            int item=full2();
            if(item==1)
            {
                printf("Stack is full\n");
            }
            else
            {
                printf("Stack is not full\n");
            }
        }
        else if(choice==12)
        {
            int item=empty2();
            if(item==1)
            {
                printf("Stack is empty\n");
            }
            else
            {
                printf("Stack is not empty\n");
            }
        }
        else if(choice==13)
        {
            int n;
            printf("Enter the number: ");
            scanf("%d",&n);
            dectobin(n);
        }
        else
        {
            printf("Invalid choice\n");
        }

    }

}
