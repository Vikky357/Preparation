/*

Sub-Array with given sum


*/

#include<bits/stdc++.h>
using namespace std;
int testcase=3;
int main()
{
   while(testcase--)
    {
        cout<<"\nStart of TC\n";
        vector<int> arr={15, 2, 4, 8, 9, 5, 10, 23};
        int sum=23,n=arr.size();
        int i=0,m=arr[0];int j;
        for(j=1;j<=n;j++)
        {

            while(m>sum && i<j-1)
            {
                m-=arr[i++];
            }
            if(m==sum)
            {
                for(int start=i;start<j;start++)
                    cout<< arr[start]<<" ";
                    return 1;
            }
            if(j<n)
                m+=arr[j];

        }
        return 0;
        }

}
