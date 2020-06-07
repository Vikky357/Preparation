/*
    3. Write a program to print the following output for the given input. You can assume the string is of odd length

Eg 1: Input: 12345
       Output:
1       5
  2   4
    3
  2  4
1      5
Eg 2: Input: geeksforgeeks
         Output:
g                         s
  e                     k
    e                 e
      k             e
        s         g
          f      r
             o
          f     r
        s         g
      k             e
    e                 e
  e                      k
g                          s

*/

#include<bits/stdc++.h>
using namespace std;
void print(string);
int main()
{
    string s;
    cin>>s;
    print(s);
}
void print(string name)
{
    int len=name.size();
    for(int i=0;i<len;i++)

    {
        int j=len-1-i;
        for(int k=0;k<len;k++)
            {
                 //printf("%d\n",i);
                 if(i==k || j==k)
                    cout<<name[k];
                else
                    cout<<" ";
            }

            //cout<<start<<" "<<end1<<"\n";
            cout<<"\n";
}
}
