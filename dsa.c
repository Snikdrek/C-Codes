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
  head=temp;
  return head;

}
struct node *addatend(struct node *head,int data)
{
  struct node *temp=malloc(sizeof(struct node));
  struct node *p=head;//eta diye iterate korbo
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
struct node *deletefirst(struct node *head)
{
    struct node *temp=head;
    head=head->next;//next head e shift jabe
    head->prev=NULL;
    free(temp);
    temp=NULL;
    return head;
}
struct node *deletelast(struct node *head)
{
    struct node *temp=head;
    struct node  *temp2=NULL;
    while(temp->next!=NULL)
    {
        temp=temp->next;//temp last e shift hobe
    }
    temp2=temp->prev;//temp2 last er previous node
    temp2->next=NULL;//last er previous node er next null hobe
    free(temp);
    temp=NULL;
    return head;
}
struct node *deleteatpos(struct node *head,int pos)
{
    struct node *temp=head;
    struct node *temp2=NULL;
    if(pos==1)//first node delete hoile
    {
        head=head->next;
        head->prev=NULL;
        free(temp);
        temp=NULL;
        return head;
    }
    for(int i=1;i<pos-1;i++)
    {
        temp=temp->next;
    }
    temp2=temp->prev;
    temp2->next=temp->next;//ekebare porer tar sathe link korlam
    temp->next->prev=temp2;//temp er next er previous hobe temp2
    free(temp);
    temp=NULL;
    return head;
}
void print(struct node *head)
{
    struct node *temp=head;
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

/// 
/// 
/// 
///  
/// 
/// 
/// 
/// 
/// 
/// 
/// 
/// 
//creating circular singly linked list
struct nodec
{
  int data;
  struct nodec *next;
  struct nodec *prev;
};
struct nodec *addemtc(int data)
{
  struct nodec *temp=malloc(sizeof(struct nodec));
  temp->data=data;
  temp->next=temp;
  return temp;
}
struct nodec *addatendc(struct nodec *tail,int data)
{
  struct nodec *temp=malloc(sizeof(struct nodec));
  temp->data=data;
  temp->next=tail->next;
  tail->next=temp;
  tail=temp;//tail er next temp hobe
  return tail;
}
void printc(struct nodec *tail)
{
  struct nodec *p=tail->next;
  do
  {
    printf("%d ",p->data);
    p=p->next;
  }while(p!=tail->next);
  printf("\n");
}
struct nodec *bubblesort(struct nodec *tail)
{
    struct nodec *p,*q;
    int temp=0;
    for(p=tail->next;p->next!=tail->next;p=p->next)//for(i=0;i<n-1;i++)
    {
        for(q=p->next;q!=tail->next;q=q->next)//for(j=i+1;j<n;j++)
        {
            if(p->data>q->data)
            {
                temp=p->data;
                p->data=q->data;
                q->data=temp;
            }
        }
    }
    return tail;
}
//reverse print the circular linked list
void reverseprint(struct nodec *tail)
{
    struct nodec *p=tail->prev;
    do
    {
        printf("%d ",p->data);
        p=p->prev;
    }while(p!=tail->prev);
    printf("\n");
}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
   struct node *head=NULL;
    head=addtoempty(head,10);
    head=addatend(head,20);
    head=addatend(head,30);
    head=addatend(head,40);
    head=addatend(head,50);
    head=addatend(head,60);
    head=addatend(head,70);
    struct node *p=head;
    while(p!=NULL)
    {
      printf("%d ",p->data);
      p=p->next;
    }
    printf("\n");
    head=deletefirst(head);
    print(head);
    head=deletelast(head);
    print(head);
    head=deleteatpos(head,3);
    print(head);
   struct nodec *tail=NULL;
   tail=addemtc(10);
   tail=addatendc(tail,30);
   tail=addatendc(tail,20);
   tail=addatendc(tail,60);
   tail=addatendc(tail,50);
   tail=addatendc(tail,40);
   tail=addatendc(tail,70);
   printc(tail);
   bubblesort(tail);
    printc(tail);
    reverseprint(tail);
    return 0;    
}