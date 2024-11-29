#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAX 10
int stack_arr[MAX];
int top=-1;
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
int print()
{
    int i;
    if(isempty())
    {
        printf("Stack is empty\n");
        return 0;
    }
    for(i=top;i>=0;i--)
    {
        printf("%d ",stack_arr[i]);
    }
    printf("\n");

}
int main()
{
    while(true)
    {
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Print\n");
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
        else
        {
            printf("Invalid choice\n");
        }

    }

}