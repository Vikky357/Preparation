/*

Rod cutting DP


*/


#include<bits/stdc++.h>
using namespace std;
int testcase=3;
int main()
{
   while(testcase--)
    {
        cout<<"\nStart of TC\n";
        vector<int> arr={ 3,5,8,9,10,17,17,20};
        int s=arr.size();
        vector<vector<int>> dp(s+1,vector<int>(s+1));
        /*vector<int> dp(arr.size()+1);
        dp[0]=0;
        for(int i=1;i<=arr.size();i++)
        {
            for(int j=i;j<=arr.size();j++)
                dp[j]=max(dp[j],arr[i-1]+dp[j-i]);
        }
    return dp[arr.size()];*/
    for(int i=0;i<=s;i++)
        {
            for(int j=0;j<=s;j++)
            {
                if(i==0 || j==0)
                    dp[i][j]=0;
                else if(j>=i)
                    dp[i][j]=max( dp[i][j-i]+ arr[i-1],dp[i-1][j]);
                else
                    dp[i][j]=dp[i-1][j];
            }
        }
        return dp[s][s];
    }
}
