
#include<bits/stdc++.h>
#define pb push_back
using namespace std;
struct node{
    int data;
    node* left;
    node* right;
};
//create a root
struct node *createnode(int data)
{
    struct node *p= (struct node *)malloc(sizeof(struct node));
    p->left=NULL;
    p->right=NULL;
    p->data=data;
    return p;
}
//insert a new node in the binary search tree
struct node *insert(struct node *root,int data)
{
    if(root==NULL)
    {
        return createnode(data);
    }
    if(data<root->data)
    {
        root->left=insert(root->left,data);
    }
    else if(data>root->data)
    {
        root->right=insert(root->right,data);
    }
    return root;
}
vector<int>v;
void inorder(struct node *root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        cout<<root->data<<" ";
        v.pb(root->data);
        inorder(root->right);
    }
}
//inorder successor
struct node *inordersuccessor(struct node *root)
{
    struct node *current=root;
    while(current && current->left!=NULL)
    {
        current=current->left;
    }
    return current;
}
//inorder predecessor
struct node *inorderpredecessor(struct node *root)
{
    struct node *current=root;
    while(current && current->right!=NULL)
    {
        current=current->right;
    }
    return current;
}

vector<int>nullchilds(100);

int main()
{
    struct node *root=NULL;
    root=insert(root,10);
    root=insert(root,5);
    root=insert(root,20);
    root=insert(root,8);
    root=insert(root,3);
    root=insert(root,7);
    root=insert(root,15);
    root=insert(root,25);
    root=insert(root,2);
    root=insert(root,9);
    root=insert(root,13);
    root=insert(root,17);
    root=insert(root,22);
    root=insert(root,27);
    inorder(root);
    /*
    The tree looks like this:
             10
           /    \
          5       20
         / \      / \
        3   8    15 25
       /   / \   / \  / \
      2   7   9 13 17 22 27
     / \
    */
    cout<<endl;
    for(int i=0;i<nullchilds.size();i++)//fix it it is not printing nullchilds
    {
        cout<<nullchilds[i]<<" ";
    }
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<" ";
    }
}