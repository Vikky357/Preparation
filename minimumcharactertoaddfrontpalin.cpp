//Minimum character to insert beginning to make a palindrome->orignalstring+$+reversestring
//Longest prefix which is also suffix->lps[lastvalue]
//Minimum character to insert end to make palindrome->reversestring+$+originalstring
#include<bits/stdc++.h>
using namespace std;
int testcase=1;
vector<int> lpstable(string arr);
int main()
{
   while(testcase--)
    {
        cout<<"\nStart of TC\n";
        string s="AACECAAAA";
        string b=s;
        reverse(b.begin(),b.end());
        s+="$"+b;
        vector<int> lps=lpstable(s);
       // cout<<lps.back()<<"\n";
        return (b.size()-lps.back());
    }
}
vector<int> lpstable(string arr)
{
    int size=arr.size();
    int i=1,len=0;
    vector<int> lps(size,0);
    while(i<size)
    {
        if(arr[i]==arr[len])
        {
            lps[i++]=++len;
        }
        else if(len)
            len=lps[len-1];
        else
            lps[i++]=0;
    }
    //cout<<lps[size-1];
    return lps;
}
