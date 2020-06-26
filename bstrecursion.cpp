/*
      Binary Serach Tree Using Recrusion
      
      */
#include<bits/stdc++.h>
using namespace std;
int testcase=1;
struct Tree
{
    int data;
    Tree* left;
    Tree* right;
}*root;
Tree* getnewnode(int num)
{
    Tree* newnode=new Tree();
    newnode->data=num;
    newnode->left=newnode->right=NULL;
    return newnode;
}
Tree* insert(Tree* root,int num)
{

    if(root==NULL)
    {
        //cout<<"root\n";
        root=getnewnode(num);
    }
    if(root->data==num)
        return root;
    else if(num<=root->data)
    {
        //cout<<"Left\n";
        root->left=insert(root->left,num);
    }
    else
    {
        //cout<<"Right\n";
        root->right=insert(root->right,num);
    }
    return root;
}
void display(Tree* root)
{

        if(root==NULL)
        {
            return;
        }
        //cout<<root->data<<" "; Proorder
        display(root->left);
        cout<<root->data<<" ";
        display(root->right);
}
void predisplay(Tree* root)
{

        if(root==NULL)
        {
            return;
        }
        cout<<root->data<<" ";
        predisplay(root->left);
        predisplay(root->right);
}
int searc(Tree* root,int n)
{
    if(root->data==n)
        return 1;
    else if(root->data>n && root->left!=NULL)
        return searc(root->left,n);
    else if(root->data<n && root->right!=NULL)
        return searc(root->right,n);
    return 0;
}
Tree* findmin(Tree* root)
{
    while(root->left)
        root=root->left;
    return root;
}

Tree* del(Tree* root,int n)
{
    if(root==NULL)
        return root;
    else if(root->data>n)
        root->left=del(root->left,n);
    else if(root->data<n)
        root->right=del(root->right,n);
    else
    {
        if(root->left==NULL && root->right==NULL)
        {
            delete (root);
            root=NULL;
            return root;
        }
        if(root->left==NULL)
        {
            Tree* temp=root;
            root=root->right;
            delete temp;
            return root;
        }
        if(root->right==NULL)
        {
            Tree* temp=root;
            root=root->left;
            delete temp;
            return root;
        }
        else
        {
            Tree* temp=findmin(root->right);
            root->data=temp->data;
            root->right=del(root->right,temp->data);
        }

    }
    return root;

}
void postorder(Tree* root)
{
    if(root==NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

int main()
{
   while(testcase--)
    {
        root=insert(root,12);
        root=insert(root,10);
        root=insert(root,20);
        root=insert(root,9);
        root=insert(root,11);
        root=insert(root,10);
        root=insert(root,12);
        root=insert(root,12);
        root=insert(root,22);
        predisplay(root);
        cout<<"\n";
        //cout<<searc(root,8);
        //searc(root,10)?cout<<"Found":(cout<<"Not Found");
        //del(root,10);
        cout<<"\n";
        postorder(root);

    }
}
