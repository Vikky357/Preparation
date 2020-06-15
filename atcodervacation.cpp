#include<bits/stdc++.h>
using namespace std;
int main()
{

    int days;
    cin>>days;z
    vector<vector<int>> v(days,vector<int>(3,0));
    for(int i=0;i<days;i++)
    {
        for(int j=0;j<3;j++)
        {
            cin>>v[i][j];
        }
    }
    vector<vector<int>> dp(days,vector<int>(3,0));
    for(int i=0;i<3;i++)
        dp[0][i]=v[0][i];
    for(int i=1;i<days;i++)
    {
        dp[i][0]=v[i][0]+max(dp[i-1][1],dp[i-1][2]);
        dp[i][1]=v[i][1]+max(dp[i-1][0],dp[i-1][2]);
        dp[i][2]=v[i][2]+max(dp[i-1][0],dp[i-1][1]);
    }
    return max(max(dp[days-1][0],dp[days-1][1]),dp[days-1][2]);

}
