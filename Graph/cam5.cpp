#include<bits/stdc++.h>
using namespace std;
int testcase=2;
int n,m;
vector<int> g[1005];
int visited[1005];
int c;
void bfs(int i);
void dfs(int i);
int main()
{
   while(testcase--)
    {
        cout<<"\nStart of TC\n";
        cin >>n >>m;
        int x,y;
        memset(g,0,sizeof(g));
        memset(visited,0,sizeof(visited));
        c=0;
        for(int i=0;i<m;i++)
        {
            cin >>x >>y;
            g[x].push_back(y);
            g[y].push_back(x);
        }
        for(int i=0;i<n;i++)
        {
            cout<<i<<"->";
            for(int j=0;j<g[i].size();j++)
                cout<<g[i][j]<<" ";
            cout<<"\n";
        }
        cout<<"\n";
        for(int i=0;i<n;i++)
        {
                if(visited[i]==0)
                {
                    c++;
                    //visited[i]=1;
                    dfs(i);
                }

        }

        cout<< c<<"\n";
    }
}
void bfs(int i)
{
    queue<int> q;
    q.push(i);
    while(!q.empty())
    {
        int temp=q.front();
        q.pop();
        for(int j=0;j<g[temp].size();j++)
        {
            int index=g[temp][j];
            if(visited[index]==0)
            {
                visited[index]=1;
                q.push(index);
            }
        }
    }
}
void dfs(int  i)
{
    visited[i]=1;
    for(int j=0;j<g[i].size();j++)
    {
        if(visited[g[i][j]]==0)
        {
            visited[g[i][j]]=1;
            dfs(g[i][j]);
        }
    }
}
