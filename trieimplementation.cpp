/*

Trie Implentation->Insert,Search,Delete,Prefixcount


*/

/*

Trie data structures
*/
/**



#include<bits/stdc++.h>
using namespace std;
#define f(root) for(int i=0;i<26;i++){root->child[i]=NULL;}
struct Trie
{
    char data;
    bool wc;
    Trie* child[26];
}*root;
Trie* getnewnode()
{
    Trie* newnode=new Trie();
    f(newnode);
    return newnode;
}
void insert(string s)
{
    Trie* curr=root;
    int index;
    for(int i=0;i<s.size();i++)
    {
        index=s[i]-'a';
        if(curr->child[index]==NULL)
                curr->child[index]=getnewnode();
        curr=curr->child[index];
        curr->data=s[i];
        curr->wc=false;
    }
    curr->wc=true;
}
bool search(string n)
{
    Trie* curr=root;
    int index;
    for(int i=0;i<n.size();i++)
    {
        index=n[i]-'a';
        if(curr->child[index]==NULL)
         return false;
        curr=curr->child[index];
    }
    if(curr->wc)
        return true;
    return false;
}
int main()
{
    root=getnewnode();
    insert("abcd");
    cout<<search("abcd");
}


    **/
#include<bits/stdc++.h>
#define fo(root) for(int i=0;i<26;i++){root->child[i]=NULL;}
using namespace std;
struct Trie
{
    char data;
    Trie* child[26];
    int wc;
    bool ls;
};
Trie *root;
Trie arr[100];
int poolcount;
void init()
{
    poolcount=0;
    root=&arr[poolcount++];
    root->data='/';
    fo(root);
}
Trie* getNewNode(char c)
{
    //cout<<"Hai";
    Trie* newNode=&arr[poolcount++];
    newNode->data=c;
    fo(newNode);
    newNode->wc=0;
    newNode->ls=false;
    return newNode;
}
void insert(string a)
{
    Trie* curr=root;
    for(int i=0;i<a.size();i++)
    {
        int index=a[i]-'a';
        if(curr->child[index]==NULL)
        {
            curr->child[index]=getNewNode(a[i]);
            //cout<<"Before finished\t";
        }
        curr->child[index]->wc+=1;
        curr=curr->child[index];
        //cout<<"End\n";

    }
    curr->ls=true;
    //cout<<"Finish";
}
void suffixinsert(string a)
{
    Trie* curr=root;
    for(int i=a.size()-1;i>=0;i--)
    {
        int index=a[i]-'a';
        if(curr->child[index]==NULL)
        {
            curr->child[index]=getNewNode(a[i]);
            //cout<<"Before finished\t";
        }
        curr->child[index]->wc+=1;
        curr=curr->child[index];
        //cout<<"End\n";

    }
    curr->ls=true;
    //cout<<"Finish";
}
void display(string a)
{
    Trie* curr=root;
    for(int i=0;i<a.size();i++)
    {
        int index=a[i]-'a';
        if(curr->child[index]==NULL)
        {
            cout<<"Not Found\t";
            break;
        }
        curr=curr->child[index];
        cout<<curr->data;
    }
}

bool search(string a)
{
    Trie* curr=root;
    for(int i=0;i<a.size();i++)
    {
        int index=a[i]-'a';
        if(curr->child[index]==NULL || curr->child[index]->wc==0)
            return false;
        curr=curr->child[index];
    }
    //if(curr->ls)
        return true;
    //return false;
}
bool suffixsearch(string a)
{
    Trie* curr=root;
    for(int i=a.size()-1;i>=0;i--)
    {
        int index=a[i]-'a';
        if(curr->child[index]==NULL || curr->child[index]->wc==0)
            return false;
        curr=curr->child[index];
    }
    //if(curr->ls)
        return true;
    //return false;
}
bool del(string a)
{
    if(search(a))
    {

        Trie* curr=root;
        int index;
        for(int i=0;i<a.size();i++)
        {
            index=a[i]-'a';
            curr->child[index]->wc-=1;
            curr=curr->child[index];
        }
        return 1;
    }
    return 0;
}
int prefixcount(string a)
{
    Trie* curr=root;
    int index;
    for(int i=0;i<a.size();i++)
    {
        index=a[i]-'a';
        if(curr->child[index]==NULL || curr->child[index]->wc==0)
            return 0;
        curr=curr->child[index];
    }
    return curr->wc;
}
int suffixcount(string a)
{
    Trie* curr=root;
    int index;
    for(int i=a.size()-1;i>=0;i--)
    {
        index=a[i]-'a';
        if(curr->child[index]==NULL || curr->child[index]->wc==0)
            return 0;
        curr=curr->child[index];
    }
    return curr->wc;
}
int main()
{
   init();
   string a="geeksforgeeks";
   //char a[4]={'a','b','c','\0'};
   insert(a);
   insert("geeks");
   //cout<<"Insert Finished\n";
   //display(a);
   //cout<<"Display Finished\n";
   string b="geeksf";
   cout<<search(b);
   del(a);
   cout<<search(b);
   insert("geeksforgeeks");
   cout<<prefixcount("ge");
   string a="google";
   string b="apple";
   suffixinsert(a);
   suffixinsert(b);
   cout<<suffixsearch("le");
   cout<<suffixcount("le");

}
