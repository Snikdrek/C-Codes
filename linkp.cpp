#include<bits/stdc++.h>
#define pb push_back
using namespace std;
struct node{
    int data;
    struct node *next;
};
struct node *createnode(int data)
{
    struct node *p=(struct node *)malloc(sizeof(struct node));
    p->data=data;
    p->next=NULL;
    return p;
};
struct node *insert(struct node *head,int data)
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
    }
    return head;
}
void print(struct node *head)
{
    struct node *temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
struct node *addatbegginning(struct node *head,int data)
{
    struct node *p=createnode(data);
    if(head==NULL)
    {
        head=p;
    }
    else
    {
        p->next=head;
        head=p;
    }
    return head;
}
struct node *addatend(struct node *head,int data)
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
    }
    return head;
} 
struct node *addatposition(struct node *head,int data,int pos)
{
    struct node *p=createnode(data);
    if(head==NULL)
    {
        head=p;
    }
    else
    {
        struct node *temp=head;
        for(int i=0;i<pos-1;i++)
        {
            temp=temp->next;
        }
        p->next=temp->next;
        temp->next=p;
    }
    return head;
}
struct node *deleteatbegginning(struct node *head)
{
    if(head==NULL)
    {
        return NULL;
    }
    else
    {
        struct node *temp=head;
        head=head->next;
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
        struct node *temp1=head;
        while(temp->next!=NULL)
        {
            temp1=temp;
            temp=temp->next;
        }
        temp1->next=NULL;
        free(temp);
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
        struct node *temp1=head;
        for(int i=0;i<pos-1;i++)
        {
            temp1=temp;//store the previous node
            temp=temp->next;//store the current node
        }
        temp1->next=temp->next;//link the previous node to the next node of the current node
        free(temp);
    }
    return head;
}
void reverseprint(struct node *head)
{
    if(head==NULL)
    {
        return;
    }
    reverseprint(head->next);
    cout<<head->data<<" ";
}
void sortbybubble(struct node *head)
{
    struct node *temp=head;
    struct node *temp1=head;
    while(temp!=NULL)
    {
        while(temp1!=NULL)
        {
            if(temp->data>temp1->data)
            {
                int t=temp->data;
                temp->data=temp1->data;
                temp1->data=t;
            }
            temp1=temp1->next;
        }
        temp=temp->next;
    }
    print(head);
}
void findelement(struct node *head,int data)
{
    struct node *temp=head;
    int count=0;
    while(temp!=NULL)
    {
        if(temp->data==data)
        {
            cout<<"Element found at position "<<count+1;
            return;
        }
        count++;
        temp=temp->next;
    }
    cout<<"Element not found";
}
int main(
)
{
    struct node *head=NULL;
    head=insert(head,10);
    head=insert(head,20);
    head=insert(head,30);
    print(head  );
    cout<<endl;
    struct node *temp=head;
    temp=addatbegginning(temp,5);
    temp=addatend(temp,40);
    print(temp);
    cout<<endl;
    temp=addatposition(temp,15,2);
    print(temp);
    cout<<endl;
    reverseprint(temp);
    cout<<endl;
    findelement(temp,15);
    cout<<endl;
    return 0;
}