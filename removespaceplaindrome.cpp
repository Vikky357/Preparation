/*

Given a sentence of string, in that remove the palindrome words and print theremaining.
Input:He did a good deed
Output:He goodInput:Hari speaks malayalam
Output:Hari speaks

*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    getline(cin,s);
    int start=0;
    int en=start;
    while(en<=s.size())
    {
        if(s[en]==32 || en==s.size())
        {
            int flag=false;
           for(int i=start,j=en-1;i<j;i++,j--)
           {
               if(s[i]==s[j])
                continue;
               flag=true;
           }
           if(flag)
           {
               for(int i=start;i<en;i++)
                cout<<s[i];
               cout<<" ";
           }
        while(s[en]==32 || en==s.size())
            en++;
        start=en;
        }
        while(s[en]!=32 && en<=s.size()-1)
            en++;
    }

}
