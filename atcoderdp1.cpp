#include<bits/stdc++.h>
using namespace std;
int main()
{
    int siz;
    cin>>siz;
    vector<int> arr(siz);
    for(int i=0;i<siz;i++)
        cin>>arr[i];
    vector<int> dp(siz);
    dp[0]=0;
    dp[1]=abs(arr[1]-arr[0]);
    for(int i=2;i<siz;i++)
        dp[i]=min(dp[i-2]+abs(arr[i]-arr[i-2]),dp[i-1]+abs(arr[i]-arr[i-1]));
    return dp[siz-1];
}
