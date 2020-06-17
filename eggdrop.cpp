/*
 Egg Dropping Problem
 
 
 */
 
 
 #include<bits/stdc++.h>
using namespace std;
int testcase=3;
int main()
{
   while(testcase--)
    {
        cout<<"\nStart of TC\n";
        int n,k;
        cin >>n >>k;
        vector<vector<int>> dp(n+1,vector<int>(k+1,0));
        for(int i=1;i<n+1;i++)
            dp[i][1]=i;
        for(int i=1;i<k+1;i++)
            dp[1][i]=1;
        for(int i=2;i<n+1;i++)
        {
            for(int j=2;j<k+1;j++)
            {

                dp[i][j]=INT_MAX;
                for(int x=1;x<i;x++)
                {
                    int res=1+max(dp[x-1][j-1],dp[i-x][j]);
                    if(res<dp[i][j])
                        dp[i][j]=res;
                }

            }
        }
        cout<<dp[n][k]<<"\n";

    }
}
