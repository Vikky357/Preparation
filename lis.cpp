/*

Longest Increasing Subsequence

*/


/*

    Longest Increasing subsequence


    */

#include<bits/stdc++.h>
using namespace std;
int testcase=3;
int main()
{
   while(testcase--)
    {
        cout<<"\nStart of TC\n";
        int s;
        cin>>s;
        vector<int> arr(s);
        for(int i=0;i<s;i++)
        {
            cin >>arr[i];
        }
        vector<int> dp(s);
        dp[0]=1;
        for(int i=1;i<s;i++)
        {
            dp[i]=1;
            for(int j=0;j<i;j++)
            {
                if(arr[i]>arr[j] && dp[i]<dp[j]+1)
                    dp[i]+=1;
            }
        }
        cout<<*max_element(dp.begin(),dp.end());
        int index=0;
        for(int i=s-1;i>=0;i--)
        {
            if(dp[i]>dp[index])
            {
                index=i;
                //cout<<index<<" ";
            }
        }
        //cout<<dp[index]<<"\n";
        vector<int> res;
        res.push_back(arr[index]);
        for(int i=index-1;i>=0;i--)
        {
            if(arr[i]<arr[index] && (dp[index]==dp[i]+1))
            {

                res.push_back(arr[i]);
                index=i;
            }
        }

        reverse(res.begin(),res.end());
        for(auto i:res) cout<<i<<" ";
    }
}
