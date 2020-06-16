/*

SUBSET PROBLEM


*/


#include<bits/stdc++.h>
using namespace std;
int testcase=3;
int main()
{
   while(testcase--)
    {
        cout<<"\nStart of TC\n";
        vector<int> arr={1, 2, 3, 4, 5};
        int sum=10;
        int siz=arr.size();
        vector<vector<bool>> dp(siz+1,vector<bool>(sum+1,false));
        for(int i=0;i<=siz;i++)
        {
            for(int j=0;j<=sum;j++)
            {
                if(j==0)
                    dp[i][j]=true;
                else if(i==0)
                    dp[i][j]=false;
                else if(arr[i-1]<=j)
                    dp[i][j]=dp[i-1][j-arr[i-1]]||dp[i-1][j];
                else
                    dp[i][j]=dp[i-1][j];
            }
        }
        cout<<dp[siz][sum]<<"\n";
        for(int i=0;i<=siz;i++)
        {
            for(int j=0;j<=sum;j++)
            {
                cout<<dp[i][j]<<" ";

            }
            cout<<"\n";
        }
    return 1;
    }
}
