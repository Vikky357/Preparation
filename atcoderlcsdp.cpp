/*

Longest Common Subsequence


*/


#include<bits/stdc++.h>
using namespace std;
int testcase=3;
string lcs(string s1,string s2);
int main()
{
   while(testcase--)
    {
        string s1,s2;
        cin >>s1 >>s2;
        cout<<lcs(s1,s2);
    }
}
string lcs(string s1,string s2)
{
    int s1len=s1.size();
    int s2len=s2.size();
    vector<vector<int>> dp(s1len+1,vector<int>(s2len+1));
    for(int i=0;i<=s1len;i++)
    {
        for(int j=0;j<=s2len;j++)
        {
            if(i==0 || j==0)
            {
                dp[i][j]=0;
            }
            else if(s1[i-1]==s2[j-1])
                dp[i][j]=1+dp[i-1][j-1];
            else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    /*for(int i=0;i<=s1len;i++)
    {
        for(int j=0;j<=s2len;j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<"\n";
    }*/
    string s;
    //return dp[s1len][s2len];
    int i=s1len,j=s2len;
    while(i>0 && j>0)
    {
        if(s1[i-1]==s2[j-1])
        {
            s.push_back(s1[i-1]);
            i--;
            j--;
        }
        else if(dp[i-1][j]>dp[i][j-1])
            i--;
        else
            j--;
    }
    //cout<<dp[s1len][s2len];
    reverse(s.begin(),s.end());
    return ((s.size()==0)? "0":s);
}
