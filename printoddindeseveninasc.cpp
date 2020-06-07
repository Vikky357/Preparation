/*
    2. Write a program to sort the elements in odd positions in descending order and elements in ascending order

Eg 1: Input: 13,2,4,15,12,10,5
        Output: 13,2,12,10,5,15,4
Eg 2: Input: 1,2,3,4,5,6,7,8,9
        Output: 9,2,7,4,5,6,3,8,1
        */
#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> a={13,2,4,15,12,10,5};
    int len=a.size();
    for(int i=0;i<len-1;i++)
    {
        int j=(i%2)?1:0;
        for(;j<len-2;j+=2)
        {
            if(i%2==0)
            {
                if(a[j]<a[j+2])
                    swap(a[j],a[j+2]);
            }
            else
            {
                if(a[j]>a[j+2])
                    swap(a[j],a[j+2]);
            }
        }
    }
    for(auto i:a)
        cout<<i<<" ";
}
