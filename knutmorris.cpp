/*


KnutMorris Algorithm for substring



*/


#include<bits/stdc++.h>
using namespace std;
int findmatch(string name,string pattern);
vector<int> kmp(string pattern);
int main()
{
    string name;
    cin>>name;
    string pattern;
    cin>>pattern;
    cout<<findmatch(name,pattern);
}
int findmatch(string name,string pattern)
{
    int m=name.size();
    int n=pattern.size();
    vector<int> lps=kmp(pattern);
    for(int i=0,j=0;i<m;)
    {
        if(name[i]==pattern[j])
        {
            i++;
            j++;
        }
        if(j==n)
        {
            cout<<"Found";
            return i-j;
        }
        if(i<m && (name[i]!=pattern[j]))
            j?j=lps[j-1]:i++;
    }
    return -1;
}
vector<int> kmp(string pattern)
{
    int n=pattern.size();
    vector<int> lptable(n,0);
    for(int i=1,len=0;i<n;)
    {
        if(pattern[i]==pattern[len])
        {
            lptable[i++]=++len;
        }
        if(len)
        {
            len=lptable[len-1];
        }
        else
            lptable[i++]=0;

    }
    return lptable;
}
