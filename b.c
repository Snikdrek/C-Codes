#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;   
    struct node *link;
};

struct node *addtoempty(int data) {
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->link = temp;
    return temp;
}

// Inserting at the beginning of a circular singly linked list
struct node *addatbeg(struct node *tail, int data) {
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->link = tail->link;
    tail->link = temp;
    return tail;
}

// Inserting at the end of a circular singly linked list
struct node *addatend(struct node *tail, int data) {
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->link = tail->link;
    tail->link = temp;
    tail = temp;
    return tail;
}
void print(struct node *tail)
{
    struct node *p = tail->link;
    do
    {
        printf("%d ", p->data);
        p = p->link;
       
           } while (p != tail->link);
    
    printf("\n");

}
//delete at beginning
struct node *delatbeg(struct node *tail)
{
    struct node *temp=tail->link;
    tail->link=temp->link;
    free(temp);
    temp=NULL;
    return tail;
}
//delete at end
struct node *delatend(struct node *tail)
{
    struct node *temp=tail->link;
    while(temp->link!=tail)
    {
        temp=temp->link;
    }
    temp->link=tail->link;
    free(tail);
    tail=temp;
    return tail;
}
int main() {
    struct node *tail = NULL;
    tail = addtoempty(10);
    tail = addatbeg(tail, 20);
    tail = addatbeg(tail, 30);
    tail = addatend(tail, 40);
    print(tail);
    tail = delatbeg(tail);
    print(tail);
    tail = delatend(tail);
    print(tail);
    return 0;
}
