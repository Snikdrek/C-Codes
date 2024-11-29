#include <iostream>
using namespace std;

#define MAX 1000

struct node
{
    int data;
    struct node *link;
};

struct node* push(int n, struct node* top)
{
    struct node *temp;
    temp = new node;
    if (temp == NULL)
    {
        cout << "Stack Overflow\n";
        return top;
    }
    temp->data = n;
    temp->link = top;
    top = temp;
    return top;
}

struct node* pop(struct node* top)
{
    if (top == NULL)
    {
        cout << "Stack Underflow\n";
        return top;
    }
    struct node* temp = top;
    top = top->link;//top=top->next in case of linked list implementation of stack in c language 
    
    //delete temp;//
   free(temp);
    temp = NULL;
    return top;
}

void print(struct node* top)
{
    if (top == NULL)
    {
        cout << "Stack is empty\n";
        return;
    }
    struct node* temp = top;
    while (temp != NULL)
    {
        cout << temp->data << endl;
        temp = temp->link;
    }
}

int main()
{
    struct node* top = NULL;
    top = push(10, top);
    top = push(20, top);
    top = push(30, top);
    top = push(40, top);
    top = push(50, top);
    print(top);
    top = pop(top);
    cout << "After pop\n";
    print(top);
    return 0;
}
