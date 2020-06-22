/*
  Longest palindromic substring
  
*/

#include<bits/stdc++.h>
using namespace std;
int testcase=1;
int main()
{
   while(testcase--)
    {
        cout<<"\nStart of TC\n";
        string s="forgeeksskeegfor";
        int size=s.size();
        vector<vector<int>> dp(size,vector<int>(size));
        for(int i=0;i<size;i++)
            dp[i][i]=1;
        int start=0,maxlength=1;
        for(int i=0;i<size-1;i++)
        {
            if(s[i]==s[i+1])
            {
                dp[i][i+1]=1;
                start=i;
                maxlength=2;
            }
        }
        for(int k=3;k<size;k++)
        {
            for(int i=0;i<size-k+1;i++)
            {
                int j=i+k-1;
                if(s[i]==s[j] && dp[i+1][j-1])
                {
                    dp[i][j]=1;
                    if(maxlength<k)
                    {
                        maxlength=k;
                        start=i;
                    }
            }
        }

    }
    cout<<s.substr(start,maxlength);
}
}
