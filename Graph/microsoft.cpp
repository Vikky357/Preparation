#include<bits/stdc++.h>
using namespace std;
int testcase=1;
int xindex[4]={1,0,-1,0};
int yindex[4]={0,1,0,-1};
int main()
{
   while(testcase--)
    {
        cout<<"\nStart of TC\n";
        int n;
        cin >>n;
        vector<vector<int>> arr(n,vector<int>(n));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
                cin>>arr[i][j];
        }
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
                if(arr[i][j]==1)
            q.push({i,j});
        }
        int res=-1,c=0;
        while(!q.empty())
        {
            int s=q.size();
            res++;
            for(int i=0;i<s;i++)
            {
                int x=q.front().first;
                int y=q.front().second;
                q.pop();
                c++;
                for(int i=0;i<4;i++)
                {
                    int nx=x+xindex[i];
                    int ny=y+yindex[i];
                    if((nx>=0 && nx<n) &&(ny>=0 && ny<n) && (arr[nx][ny]==0) )
                       {
                           arr[nx][ny]=1;
                           q.push({nx,ny});
                       }
                }
            }
        }
        return (c==n*n ? res :-1);

    }
}
