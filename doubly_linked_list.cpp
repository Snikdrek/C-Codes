#include<bits/stdc++.h>
#define pb push_back
using namespace std;
struct node{
    int data;
    struct node *next;
    struct node *prev;
};
struct node *createnode(int data)
{
    struct node *p=(struct node *)malloc(sizeof(struct node));
    p->data=data;
    p->next=NULL;
    p->prev=NULL;
    return p;
};
struct node *insertatbeginning(struct node *head,int data)
{
    struct node *p=createnode(data);
    if(head==NULL)
    {
        head=p;
    }
    else
    {
        p->next=head;
        head->prev=p;
        head=p;
    }
    return head;
}
struct node *insertatend(struct node *head,int data)
{
    struct node *p=createnode(data);
    if(head==NULL)
    {
        head=p;
    }
    else
    {
        struct node *temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=p;
        p->prev=temp;
    }
    return head;
}
struct node *insertatposition(struct node *head,int data,int pos)
{
    struct node *p=createnode(data);
    if(head==NULL)
    {
        head=p;
    }
    else
    {
        struct node *temp=head;
        for(int i=1;i<pos-1;i++)
        {
            temp=temp->next;
        }
        p->next=temp->next;
        temp->next->prev=p;
        temp->next=p;
        p->prev=temp;
    }
    return head;
}
struct node *deleteatbeginning(struct node *head)
{
    if(head==NULL)
    {
        return NULL;
    }
    else
    {
        struct node *temp=head;
        head=head->next;
        head->prev=NULL;
        free(temp);
    }
    return head;
}
struct node *deleteatend(struct node *head)
{
    if(head==NULL)
    {
        return NULL;
    }
    else
    {
        struct node *temp=head;
        while(temp->next->next!=NULL)
        {
            temp=temp->next;
        }
        struct node *t=temp->next;
        temp->next=NULL;
        free(t);
    }
    return head;
}
struct node *deleteatposition(struct node *head,int pos)
{
    if(head==NULL)
    {
        return NULL;
    }
    else
    {
        struct node *temp=head;
        for(int i=1;i<pos-1;i++)
        {
            temp=temp->next;
        }
        struct node *t=temp->next;
        temp->next=temp->next->next;
        temp->next->prev=temp;
        free(t);
    }
    return head;
}
void traverse(struct node *head)
{
    struct node *temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
void reverse(struct node *head)
{
    struct node *temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;//reaching to the last node
    }
    while(temp!=NULL)//printing the linked list in reverse order by traversing from the last node
    {
        cout<<temp->data<<" ";//printing the data of the node
        temp=temp->prev;
    }
    cout<<endl;
}
void findelement(struct node *head,int data)
{
    struct node *temp=head;
    int pos=1;
    while(temp!=NULL)
    {
        if(temp->data==data)
        {
            cout<<"Element found at position "<<pos<<endl;
            return;
        }
        pos++;
        temp=temp->next;
    }
    cout<<"Element not found"<<endl;
}
int main()
{
    struct node *head=NULL;
    head=insertatbeginning(head,10);
    head=insertatbeginning(head,20);
    head=insertatbeginning(head,30);
    head=insertatend(head,40);
    head=insertatend(head,50);
    head=insertatend(head,60);
    head=insertatposition(head,70,4);
    traverse(head);
    head=deleteatbeginning(head);
    traverse(head);
    head=deleteatend(head);
    traverse(head);
    head=deleteatposition(head,3);
    traverse(head);
    reverse(head);
    findelement(head,50);
    findelement(head,100);
}