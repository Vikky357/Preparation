/*
    4. Find if a String2 is substring of String1. If it is, return the index of the first occurrence. else return -1.

Eg 1:Input:
        String 1: test123string
         String 2: 123
        Output: 4
Eg 2: Input:
        String 1: testing12
        String 2: 1234
        Output: -1
        */

#include<bits/stdc++.h>
using namespace std;
int main()
{

    string s1,s2;
    cin>>s1;
    cin>>s2;

    /*
    Built-in Function

    int index=s1.find(s2);
    if(index!=string::npos)
        return index;
    return -1;

    */
for(int i=0;i<= (s1.size()-s2.size());i++)
{
    if(s1[i]==s2[0])
    {
         int found=1;
        for(int j=1;j<s2.size();j++)
        {
            if(s1[i+j]!=s2[j])
            {
               found=0;
                break;
            }
        }
        if(found)
            return i;
    }
}
return -1;
}
