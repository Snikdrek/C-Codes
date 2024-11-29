#include<bits/stdc++.h>
#include<stdlib.h>
#define pb push_back
#define nl "\n"
#define pob pop_back    
#define fire(n) for (ll i = 0; i < n; i++)    
using namespace std;
struct node{
    int data;
    node* link;
};
struct node *front=NULL;
struct node *rear=NULL;
struct node *insert(int data,struct node *rear)
{
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));
    if(temp==NULL)
    {
        printf("Queue Overflow\n");
        return rear;
    }
    temp->data=data;
    temp->link=NULL;
    if(front==NULL)//if queue is empty
    {
        front=temp;
    }
    else//if queue is not empty
    {
        rear->link=temp;//link the previous node to the new node
    }
    rear=temp;//make the new node as rear
};
struct node *del(struct node *front)
{
    if(front==NULL)
    {
        printf("Queue Underflow\n");
        return front;
    }
    struct node *temp=front;
    front=front->link;
    free(temp);
    temp=NULL;
    return front;
};
void print(struct node *front)
{
    
    if(front==NULL)    {
        printf("Queue is empty\n");
        return;
    }
    struct node *temp=front;
    while(temp!=NULL)
    {
        printf("%d\n",temp->data);
        temp=temp->link;
    }
}
//search and return the position of the element
int search(struct node *front,int data)
{
    struct node *temp=front;
    int pos=1;
    while(temp!=NULL)
    {
        if(temp->data==data)
        {
            return pos;
        }
        pos++;
        temp=temp->link;
    }
    return -1;
}
int main()
{
    rear=insert(10,rear);
    cout<<"front"<<front->data<<nl;
    cout<<"rear"<<rear->data<<nl;
    
    rear=insert(20,rear);
    cout<<"front"<<front->data<<nl;
    cout<<"rear"<<rear->data<<nl;
    
    rear=insert(30,rear);
    cout<<"front"<<front->data<<nl;
    cout<<"rear"<<rear->data<<nl;
    
    rear=insert(40,rear);
    cout<<"front"<<front->data<<nl;
    cout<<"rear"<<rear->data<<nl;
    
    rear=insert(50,rear);
    cout<<"front"<<front->data<<nl;
    cout<<"rear"<<rear->data<<nl;
    
    cout<<"Queue is\n";
    print(front);
    front=del(front);
    front=del(front);
    cout<<"Queue after deletion\n";
    print(front);
    cout<<"front"<<nl;
   int p1=search(front,front->data);
    cout<<front->data<<nl;
    cout<<"position of front is "<<p1<<nl;
    cout<<"rear"<<nl;
    int p2=search(front,rear->data);
    cout<<"position of rear is "<<p2<<nl;
    cout<<rear->data<<nl;
    return 0;
}