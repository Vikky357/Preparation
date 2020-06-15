#include<bits/stdc++.h>
using namespace std;
int main()
{
    unordered_map<char,int> m={ {'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};
    string s;
    cin>>s;
    int res=0;
    for(int i=0;i<s.size()-1;i++)
    {
        if(m[s[i]]>=m[s[i+1]])
            res+=m[s[i]];
        else
            res-=m[s[i]];
    }
    res+=m[s.back()];
    return res;
}
