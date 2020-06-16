/*

Longest Incresing Subsequence Using Binary Search->Time Complexity:O(nlogn);

*/


#include<bits/stdc++.h>
using namespace std;
int testcase=3;
int bs(vector<int>,int);
int main()
{
   while(testcase--)
    {
        cout<<"\nStart of TC\n";
        vector<int> arr={10, 22, 9, 33, 21, 50, 41, 60, 80};
        vector<int> dp;
        dp.push_back(arr[0]);
        for(int i=1;i<arr.size();i++)
        {
            if(dp.back()<arr[i])
                dp.push_back(arr[i]);
            else
            {
                int ind=bs(dp,arr[i]);
                dp[ind]=arr[i];
            }
        }
        for(auto i:dp)
            cout<<i<<" ";
        return dp.size();

    }
}
int bs(vector<int> arr,int num)
{
    int start=0,en=arr.size()-1;
    while(start<=en)
    {
        int mid=(start+en)/2;
        if(num > arr[mid])
            start=mid+1;
        else
            en=mid-1;
    }
    return start;
}
