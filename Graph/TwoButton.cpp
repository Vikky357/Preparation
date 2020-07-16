#include<bits/stdc++.h>
using namespace std;
int testcase=3;
int main()
{
   while(testcase--)
    {
        cout<<"\nStart of TC\n";
        int x,y;
        cin >>x >>y;
        queue<int> q;
        q.push(x);
        int res=-1;
        while(!q.empty())
        {
            int s=q.size();
            res++;
            for(int i=0;i<s;i++)
            {
                int n=q.front();
                q.pop();
                if(n==y)
                    return res;
                q.push(n*2);
                q.push(n-1);
            }
        }
        return res;

    }
}
