/*

  Binary Tree
 
*/

#include<bits/stdc++.h>
using namespace std;
struct Tree
{
    int data;
    Tree* left;
    Tree* right;
}*root;
Tree* getnewnode(int n)
{
    Tree* newnode=new Tree();
    newnode->data=n;
    newnode->left=newnode->right=NULL;
    return newnode;
}
void insert(int n)
{

    if(root==NULL)
    {
        cout<<"Inserted root\n";
        root=getnewnode(n);
        return;
    }
    Tree* curr=root;
    queue<Tree*> q;
    q.push(curr);
    while(!q.empty())
        {
            Tree* qnode=q.front();
            q.pop();
            if(qnode->left==NULL)
            {
                cout<<"Inserted left\n";
                qnode->left=getnewnode(n);
                break;
            }
            else
            q.push(qnode->left);
            if(qnode->right==NULL)
            {
                cout<<"Inserted right\n";
                qnode->right=getnewnode(n);
                break;
            }
            else
                q.push(qnode->right);

        }
    }
void display(Tree* root)
{
    if(root==nullptr)
        return;
    cout<<root->data<<" ";
    display(root->left);
    display(root->right);

}
int searc(Tree* root,int n)
{
    if(root==NULL)
        return 0;
    Tree* curr=root;
    queue<Tree*>q;
    q.push(curr);
    while(!q.empty())
    {
        Tree* qnode=q.front();
        if(qnode->data==n)
            return 1;
        q.pop();
        if(qnode->left)
            q.push(qnode->left);
        if(qnode->right)
            q.push(qnode->right);
    }
    return 0;

}
void delmod(Tree* node)
{
    Tree* curr=root;
    queue<Tree*> q;
    q.push(curr);
    while(!q.empty())
    {
        Tree* temp=q.front();
        q.pop();
        if(temp==node)
        {
            temp=NULL;
            delete(node);
            return;
        }
        if(temp->left==node)
        {
            temp->left=NULL;
            delete(node);
            return;
        }
        else
            q.push(temp->left);
        if(temp->right==node)
        {
            temp->right=NULL;
            delete(node);
            return;
        }
        else
            q.push(temp->right);

    }
}
void del(int n)
{
    if(root==NULL)
        return;
    if(!searc(root,n))
        return;
    Tree* curr=root,*keynode=NULL;
    Tree* qnode;
    queue<Tree*> q;
    q.push(curr);
    while(!q.empty())
    {
        qnode=q.front();
        q.pop();
        if(qnode->data==n)
        {
            keynode=qnode;

        }
        //cout<<"Executed";
        if(qnode->left)
            q.push(qnode->left);
        if(qnode->right)
            q.push(qnode->right);
    }
    if(keynode)
    {
        int x=qnode->data;
        delmod(qnode);
        keynode->data=x;
    }
}


int testcase=1;
int main()
{
   while(testcase--)
    {
        cout<<"\nStart of TC\n";
       insert(5);
       insert(3);
       insert(7);
       insert(2);
       insert(4);
       insert(8);
       display(root);
       cout<<"\n";
       //searc(root,8)?cout<<"Found":(cout<<"Not Found");
       del(5);
       display(root);


    }
}
