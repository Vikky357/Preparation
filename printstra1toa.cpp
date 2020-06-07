/*
 1. Write a program to give the following output for the given input

      Eg 1: Input: 

             Output: abbbbbbbbbb
      Eg: 2: Input: b3c6d15
             Output: bbbccccccddddddddddddddd
The number varies from 1 to 99.
*/

#include<bits/stdc++.h>
using namespace std;
void print(string);
int main()
{
    string name;
    cin >>name;
    print(name);
}
void print(string name)     //Sample input:a1b10
{
    int i=0,len=name.size(),result=0;
    while( i<len && (name[i]>47 && name[i]<58) )
        i++;
    while(i<len)
    {

        char a=name[i++];
        for(;( (name[i]>47 && name[i]<58) && name[i] );i++)
        {
            result=result*10+(int)(name[i]-48);
        }
        for(int i=0;i<result;i++)
            cout << a;
        result=0;
    }

}
