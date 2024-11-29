#include<stdio.h>
#include<stdlib.h>
struct node
{
    struct node *prev;
  int data;
  struct node *next;
};
struct node *addtoempty(struct node *head,int data)
{
struct node *temp=(struct node*)malloc(sizeof(struct node));
  temp->prev=NULL;
  temp->data=data;
  temp->next=NULL;
  head=temp;//head is the address of the first node and temp is the address of the new node so we are making head to point to the new node
  return head;
}
//inserting at beginning
struct node *addatbeg(struct node *head,int data)
{
  struct node *temp=malloc(sizeof(struct node));
  temp->prev=NULL;
  temp->data=data;
  temp->next=head;
  head->prev=temp;
  head=temp;
  return head;
}
//inserting at end
struct node *addatend(struct node *head,int data)
{
  struct node *temp=malloc(sizeof(struct node));
  struct node *p=head;//p is a pointer which will traverse the list
  temp->prev=NULL;
  temp->data=data;
  temp->next=NULL;
  while(p->next!=NULL)
  {
    p=p->next;
  }
  p->next=temp;
  temp->prev=p;
  return head;
}
//inserting at a position
struct node *addatpos(struct node *head,int data,int pos)
{
  struct node *p=malloc(sizeof(struct node));
  p->prev=NULL;
  p->data=data;
  p->next=NULL;
    struct node *temp=head;
    struct node *temp2=NULL;
if(pos==1)
    {
        p->next=head;
        head->prev=p;
        head=p;
        return head;
    }
    else{
  int i=1;
  while(i<pos-1)
  {
    temp=temp->next;
    i++;
  }
  if(temp->next==NULL)
  {
    temp->next=p;
    p->prev=temp;
  }
  else
  {
    temp2=temp->next;
    temp->next=p;
    temp2->prev=p;
    p->prev=temp;
    p->next=temp2;
   
  }
    }
    return head;
}
//deleting first node
struct node *delatbeg(struct node *head)
{
  struct node *temp=head;
  head=head->next;
  head->prev=NULL;
  free(temp);
  return head;
}
//deleting last node
struct node *delatend(struct node *head)
{
  struct node *temp=head;
  struct node *temp2=NULL;
  while(temp->next!=NULL)
  {
    temp=temp->next;
  }
  temp2=temp->prev;//temp2 is the second last node
  temp2->next=NULL;//making the second last node to point to null
  free(temp);
    temp=NULL;
  return head;
}
//deleting at a position
struct node *delatpos(struct node *head,int pos)
{
  struct node *temp=head;
  struct node *temp2=NULL;
  if(pos==1)
  {
    head=head->next;
    head->prev=NULL;
    free(temp);
    return head;
  }
  else
  {
    int i=1;
    while(i<=pos-1)
    {
      temp=temp->next;
      i++;
    }
    temp2=temp->prev;
    temp2->next=temp->next;
    temp->next->prev=temp2;
    free(temp);
    temp=NULL;
  }
  return head;
}
//sort t
int main()
{
  
  struct node *head=NULL;
    head=addtoempty(head,10);
    //add more data
    head=addatend(head,20);
    head=addatend(head,30);
    head=addatend(head,40);
    head=addatend(head,50);
    head=addatend(head,60);
    head=addatend(head,70);
    head=addatpos(head,225,3);

    struct node *p=head;
    while(p!=NULL)
    {
      printf("%d ",p->data);
      p=p->next;
    }
    head=delatbeg(head);
    head=delatend(head);
    printf("\n");
    p=head;
    while(p!=NULL)
    {
      printf("%d ",p->data);
      p=p->next;
    }
    head=delatpos(head,3);
    printf("\n");
    p=head;
    while(p!=NULL)
    {
      printf("%d ",p->data);
      p=p->next;
    }
}