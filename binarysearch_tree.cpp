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
};//double linked list
//create a new node that implies binary search tree property
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
//delete a node from the binary search tree
struct node *deletenode(struct node *root,int data)
{
    if(root==NULL)
    {
        return root;
    }
    if(data<root->data)
    {
        root->left=deletenode(root->left,data);
    }
    else if(data>root->data)
    {
        root->right=deletenode(root->right,data);
    }
    else//if the data is found
    {
        if(root->left==NULL)
        {
            struct node *temp=root->right;//store the right child in a temporary variable
            free(root);//delete the node
            return temp;//return the right child
        }
        else if(root->right==NULL)
        {
            struct node *temp=root->left;//
            free(root);
            return temp;
        }
        struct node *temp=root->right;//store the right child in a temporary variable
        while(temp->left!=NULL)//find the inorder successor
        {
            temp=temp->left;//go to the leftmost node of the right subtree
        }
        root->data=temp->data;//replace the data of the node to be deleted with the data of the inorder successor
        root->right=deletenode(root->right,temp->data);
    }
    return root;
}
//search a node in the binary search tree
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
    struct node *root=NULL;
    root=insert(root,2);
    //insert the nodes in the binary search tree
    insert(root,1);
    insert(root,4);
    insert(root,3);
    insert(root,5);
    insert(root,6);
    insert(root,8);
    insert(root,7);
    cout<<"Preorder Traversal: ";
    preorder(root);
    cout<<nl;
    /*
    The binary search tree will look like this:
       2
      / \
     1   4
        / \
       3   5
          / \
         6   8
            /   
           7

    */
 cout<<"DELETE 4\n";
    root=deletenode(root,4);

    cout<<"Preorder Traversal: ";
    preorder(root);
    cout<<nl;
    cout<<"SEARCH 5\n";
    struct node *temp=search(root,5);
    
    cout<<"Inorder Traversal: ";
    inorder(root);
    cout<<nl;
    cout<<"Postorder Traversal: ";
    postorder(root);
    return 0;
}
