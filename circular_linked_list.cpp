#include<bits/stdc++.h>
#define pb push_back
using namespace std;
//node for circular linked list
struct node{
    int data;
    struct node *next;
};
//function to create a new node
struct node *createnode(int data)
{
    struct node *p=(struct node *)malloc(sizeof(struct node));
    p->data=data;
    p->next=NULL;
    return p;
}
struct node *insertatbeginning(struct node *head,int data)
{
    struct node *p=createnode(data);
    if(head==NULL)
    {
        head=p;
        p->next=head;
    }
    else
    {
        struct node *temp=head;
        while(temp->next!=head)
        {
            temp=temp->next;
        }
        temp->next=p;
        p->next=head;
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
        p->next=head;
    }
    else
    {
        struct node *temp=head;
        while(temp->next!=head)
        {
            temp=temp->next;
        }
        temp->next=p;
        p->next=head;
    }
    return head;
}
struct node *insertatposition(struct node *head,int data,int pos)
{
    struct node *p=createnode(data);
    if(head==NULL)
    {
        head=p;
        p->next=head;
    }
    else
    {
        struct node *temp=head;
        for(int i=0;i<pos-2;i++)//traverse to the position before the position where we want to insert
        {
            temp=temp->next;
        }
        p->next=temp->next;//
        temp->next=p;
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
        while(temp->next!=head)
        {
            temp=temp->next;
        }
        temp->next=head->next;
        free(head);
        head=temp->next;
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
        while(temp->next->next!=head)
        {
            temp=temp->next;
        }
        free(temp->next);
        temp->next=head;
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
        for(int i=0;i<pos-2;i++)
        {
            temp=temp->next;
        }
        struct node *t=temp->next;
        temp->next=temp->next->next;
        free(t);
    }
    return head;
}
void searchelement(struct node *head,int ele)
{
    struct node *temp=head;
    int count=1;
    while(temp->next!=head)
    {
        if(temp->data==ele)
        {
            cout<<"Element found at position "<<count<<endl;
            return;
        }
        count++;
        temp=temp->next;
    }
    if(temp->data==ele)
    {
        cout<<"Element found at position "<<count<<endl;
        return;
    }
    cout<<"Element not found"<<endl;
}
void traverse(struct node *head)
{
    struct node *temp=head;
    while(temp->next!=head)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<temp->data<<endl;
}
int main()
{
    struct node *head=NULL;
     cout<<"insert at  beginning"<<endl;
    head=insertatbeginning(head,10);
    head=insertatbeginning(head,20);
    head=insertatbeginning(head,30);
    traverse(head);
    cout<<"insert at end"<<endl;
    head=insertatend(head,40);
    head=insertatend(head,50);
    head=insertatend(head,60);
    traverse(head);
     cout<<"insert at  position"<<endl;
    head=insertatposition(head,70,2);
    head=insertatposition(head,80,4);
    head=insertatposition(head,90,7);
    traverse(head);
    cout<<"traversal"<<endl;
    traverse(head);
     cout<<"delete at beginning"<<endl;
    head=deleteatbeginning(head);
    traverse(head);
    cout<<"delete at end"<<endl;
    head=deleteatend(head);
    traverse(head);
    head=deleteatposition(head,3);
    traverse(head);
    searchelement(head,70);
    searchelement(head,100);
    return 0;
}