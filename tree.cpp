#include<bits/stdc++.h>
#include<stdlib.h>
#define pb push_back
#define nl "\n"
#define pob pop_back
#define fire(n) for (ll i = 0; i < n; i++)      //fire(n) is a macro that will run the loop n times             
#define ou(n) cout << n << nl
#define ll long long
#define nd &&                                    //nd is a macro that will be replaced by &&
#define orr ||                                    //orr is a macro that will be replaced by ||
using namespace std;
struct node{
    int data;
    node* left;
    node* right;
};
struct node *createnode(int data)
{
    struct node *p= (struct node *)malloc(sizeof(struct node));
    p->left=NULL;
    p->right=NULL;
    p->data=data;
    return p;
}
//preorder traversal
void preorder(struct node *root)
{
    if(root!=NULL)
    {
        cout<<root->data<<" ";
        preorder(root->left);
        preorder(root->right);
    }
}
//inorder traversal
void inorder(struct node *root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
}
//postorder traversal
void postorder(struct node *root)
{
    if(root!=NULL)
    {
        postorder(root->left);
        postorder(root->right);
        cout<<root->data<<" ";
    }
}
//bst search data and print position

struct node *search(struct node *root, int key)
{
    if(root==NULL)
    {
        return NULL;
    }
    if(root->data==key)
    {
        return root;
    }
    else if(root->data>key)
    {
        return search(root->left,key);
    }
    else
    {
        return search(root->right,key);
    }
}

int main()
{
   struct node *p= createnode(2);
    struct node *p1= createnode(1);
    struct node *p2= createnode(4);
    struct node *p3= createnode(3);
    struct node *p4= createnode(5); 
    /*
         2
        / \
       1   4
           / \
            3   5
    */
    p->left=p1;
    p->right=p2;
    p2->left=p3;
    p2->right=p4;
    cout<<"Preorder traversal: ";
    preorder(p);
    cout<<nl;
    cout<<"Inorder traversal: ";
    inorder(p);
    cout<<nl;
    cout<<"Postorder traversal: ";
    postorder(p);
    search(p,3)?cout<<"Element found":cout<<"Element not found";
    cout<<nl;
    return 0;
}