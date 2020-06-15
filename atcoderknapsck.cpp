/*


Knapsack-1

*/


#include<bits/stdc++.h>
using namespace std;
int testcase=1;
int main()
{
   while(testcase--)
    {
        int n,w;
        cin>>n;
        cin>>w;
        vector<int> v(n),wt(n);
        vector<vector<int>> dp(n+1,vector<int>(w+1));
        for(int i=0;i<n;i++)
            cin>>wt[i]>>v[i];
        /*dp[0][0]=0;
        for(int i=1;i<=w;i++)
            dp[0][i]=0;
        for(int i=1;i<=n;i++)
            dp[i][0]=0;*/
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=w;j++)
            {
                if(i==0 || j==0)
                    dp[i][j]=0;
                else if(j>=wt[i-1])
                    dp[i][j]=max( dp[i-1][j-wt[i-1]]+ v[i-1],dp[i-1][j]);
                else
                    dp[i][j]=dp[i-1][j];
            }
        }
        cout<<dp[n][w];
        cout<<"\n\n\n\n";
    }
}
