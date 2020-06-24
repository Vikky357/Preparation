/*

Spoj Eko-eko 

*/


#include<bits/stdc++.h>
using namespace std;
int testcase=3;
bool bs(vector<int> arr,int mid,int n,int t)
{
    int wc=0;
    for(int i=0;i<n;i++)
    {
      wc+=max(0,arr[i]-mid);
    }
    if(wc>=t)
        return true;
    return false;
}
int main()
{
   while(testcase--)
    {
        cout<<"\nStart of TC\n";
        int n,t;
        cin>>n >>t;
        vector<int> arr(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];
        int low=0;
        int high=*max_element(arr.begin(),arr.end());
        //cout<< low<<high;
        while(high-low>1)
        {
            int mid=(low+high)/2;
            if(bs(arr,mid,n,t))
                low=mid;
            else
                high=mid-1;
        }
        if(bs(arr,high,n,t))
            return high;
        return low;
    }
}
