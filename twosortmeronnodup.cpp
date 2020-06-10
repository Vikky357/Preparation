/*

    5. Given two sorted arrays, merge them such that the elements are not repeated

Eg 1: Input:
        Array 1: 2,4,5,6,7,9,10,13
        Array 2: 2,3,4,5,6,7,8,9,11,15
       Output:
       Merged array: 2,3,4,5,6,7,8,9,10,11,13,15

*/

#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> arr1={2,4,5,6,7,9,10,13};
    vector<int> arr2={2,3,4,5,6,7,8,9,11,15};
    set<int> srt;
    for(int i=0;i<arr1.size();i++)
    {
        srt.insert(arr1[i]);
    }
    for(int i=0;i<arr2.size();i++)
    {
        srt.insert(arr2[i]);
    }
    //Print the array
    for(auto i=srt.begin();i!=srt.end();i++)
    {
        cout<<*i<<" ";
    }
}
